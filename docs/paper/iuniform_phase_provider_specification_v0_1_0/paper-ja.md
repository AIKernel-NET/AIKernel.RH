---
id: numbertheory.contract.uniform-phase.ja
title: "IUniformPhaseProvider 仕様：独立した素数位相ジェネレータの最小 Contract"
version: 0.1.0
status: companion-draft
issuer: takuya.sogawa@aikernel.net
license: CC-BY-4.0
lang: ja
created: 2026-05-25
last_updated: 2026-05-25
doi: 10.5281/zenodo.20373240
canonical_id: numbertheory.contract.uniform-phase.en
is_translation_of: numbertheory.contract.uniform-phase.en
translation_status: companion-translation
tags:
  - aikernel
  - interface-led-architecture
  - riemann-hypothesis
  - analytic-number-theory
  - uniform-distribution
  - lean
  - contract-specification
owners:
  - Takuya Sogawa
---

# IUniformPhaseProvider 仕様

## 独立した素数位相ジェネレータの最小 Contract

**著者:** Takuya Sogawa  
**ORCID:** 0009-0009-7499-2595  
**Version:** v0.1.0  
**DOI:** 10.5281/zenodo.20373240  
**正本:** English  
**副本:** Japanese

---

## 1. Abstract

本 technical note は、リーマン予想に向けた素数波動実験で用いる Provider 側の位相源を隔離するため、`IUniformPhaseProvider` の最小 Contract 仕様を定義する。仕様は Interface-Led Architecture（ILA）の語彙に基づいて記述される。すなわち、素数対数周波数を Provider、位相観測や積分処理を後段の Observer / Operator として分離し、より強い解析的数論の仮定を Provider contract から排除する。

本インターフェースの中心目的は、依存性の隔離である。素数位相を、解析接続、明示公式、零点相関、RH と同値な誤差評価と混ぜるのではなく、Provider 側の最弱不変条件として、有限個の素数対数周波数が有理数体上一次独立であり、有限トーラス上に一様分布を誘導することを抽出する。この Contract から、臨界線上の重み付き有限信号に対する固定スケールの平均二乗相殺条件を定式化できる。

本仕様はリーマン予想の証明を主張しない。将来の条件付き証明実験、Lean 形式化、および数値シミュレーションのための入力 Contract を定義するものである。本稿の貢献は、Provider の責務を Observer / Operator の責務から分離し、将来の証明アーキテクチャにおける循環論法のリスクを下げる点にある。

---

## 2. 目的と位置づけ

本仕様は、論文 *Prime-Wave Phase Transition and Conditional Proof Interfaces: A Second Interface-Led Approach to the Riemann Hypothesis* を補足する technical note である。同論文では、`IUniformPhaseProvider` が素数位相源に対する最初の分離可能な Contract として導入された。本稿では、そのアイデアを独立した仕様として展開し、実装、形式化、シミュレーションに利用できる形へ整える。

ILA 的解釈では、証明アーキテクチャは以下のように分解される。

| ILA の役割 | RH 向けの対応 | 責務 |
|---|---|---|
| Provider | 素数対数の位相源 | 独立した位相モードを供給する |
| Observer | 明示公式、チェビシェフ関数、零点スペクトル検査 | マクロな制約を観測する |
| Operator | ペロン変換、アーベル／メリン正則化、輪郭移動 | Provider 信号を解析的インターフェースへ変換する |
| Contract | 一次独立性、一様分布、相殺、非循環性 | 保証すべき条件を定義する |
| Fail-Closed | 循環的評価、欠落した一様性、不正な交換 | 証明主張を停止する |

本仕様が扱うのは Provider 側のみである。したがって、本仕様は RH の証明よりも意図的に小さい。

---

## 3. 非証明境界

**注記** 本仕様に含まれる議論および Contract は、リーマン予想を証明するものではない。後続の証明試行が注入できる Provider 側の最小インターフェースを定義するものである。

本仕様は、以下を仮定しない。

- $\zeta(s)$ の解析接続
- リーマンの明示公式
- 零点相関統計
- Montgomery の pair correlation
- $O(x^{1/2+\varepsilon})$ のような RH と同値な誤差評価
- Hilbert-Polya 型作用素
- 臨界線外零点の排除

本インターフェースが問うのは、後段の Operator が解析的数論へ接続する前に、位相源 Provider が最低限何を供給すべきか、という一点である。

---

## 4. Interface 定義

### 4.1 Interface 名

```text
IUniformPhaseProvider
```

### 4.2 入力パラメータ

有限スケール $N$ に対して、Provider は以下を公開する。

- $N \in \mathbb{N}$: 有限モード数
- $t \in \mathbb{R}$: 連続位相パラメータ。複素変数 $s$ の虚部に対応する
- $\omega_n$: 第 $n$ 周波数。素数インスタンスでは $\omega_n=\log p_n$
- $p_n$: 実際の素数でインスタンス化する場合の第 $n$ 素数

本インターフェースは、$\zeta(s)$ の解析的挙動を公開しない。

### 4.3 出力位相信号

各モードについて、Provider は次の位相を返す。

$$
\theta_n(t) = -t\omega_n \pmod{2\pi}.
$$

素数インスタンスでは、

$$
\omega_n = \log p_n,
\qquad
\theta_n(t)=-t\log p_n \pmod{2\pi}
$$

である。

Provider が返すのは位相であり、零点、誤差項、解析接続ではない。

---

## 5. Contract Requirements

`IUniformPhaseProvider` は以下の Contract を満たさなければならない。

### 5.1 Contract 1: Q-linear independence（有理数体上の一次独立性）

各有限 $N$ に対し、周波数ベクトル

$$
\omega=(\omega_1,\dots,\omega_N)
$$

は $\mathbb{Q}$ 上で一次独立でなければならない。

$$
\sum_{n=1}^{N} q_n\omega_n=0,
\quad q_n\in\mathbb{Q}
\quad\Longrightarrow\quad
q_1=\cdots=q_N=0.
$$

素数インスタンス $\omega_n=\log p_n$ では、これは素因数分解の一意性から従う。実際、分母を払った関係式

$$
\sum_{n=1}^{N} m_n\log p_n=0,
\quad m_n\in\mathbb{Z}
$$

が成立するとすれば、指数を取ることで

$$
\prod_{n=1}^{N}p_n^{m_n}=1
$$

が得られる。素因数分解の一意性により、すべての $m_n$ はゼロでなければならない。

### 5.2 Contract 2: Equidistribution on the finite torus（有限トーラス上の一様分布）

固定された $N$ に対し、位相流

$$
t \mapsto (\theta_1(t),\dots,\theta_N(t))
$$

は、Haar 測度に関して有限トーラス $\mathbb{T}^N$ 上に一様分布しなければならない。

同値に、任意の連続関数 $g:\mathbb{T}^N\to\mathbb{R}$ に対し、

$$
\lim_{T\to\infty}
\frac{1}{T}
\int_0^T
    g(\theta_1(t),\dots,\theta_N(t))\,dt
=
\int_{\mathbb{T}^N}g(x)\,d\mu_{\mathrm{Haar}}(x)
$$

が成立する。

これは Kronecker-Weyl 型の連続時間フローにおける一様分布原理である。本 Contract は、固定された有限 $N$ に対して述べられる。$N$ に一様な有効 discrepancy 評価は、最小 Provider Contract には含めず、後続の proof obligation として扱う。

### 5.3 Contract 3: Fixed-scale mean-square cancellation（固定スケール平均二乗相殺）

次の有限信号を考える。

$$
S_N(t)
=
\sum_{n=1}^{N}p_n^{-1/2}e^{i\theta_n(t)}.
$$

Contract 1 および Contract 2 の下では、固定 $N$ に対して時間平均で交差項が消え、平均二乗エネルギーは

$$
\lim_{T\to\infty}
\frac{1}{T}
\int_0^T |S_N(t)|^2\,dt
=
\sum_{n=1}^{N}\frac{1}{p_n}
$$

となる。

実際の素数重みに対して、これは標準的な素数逆数和の成長

$$
\sum_{n=1}^{N}\frac{1}{p_n}
=O(\log\log p_N)
$$

と整合する。

したがって、Provider 側の相殺 Contract は次のように記録できる。

$$
\limsup_{T\to\infty}
\frac{1}{T}
\int_0^T
\left|
\sum_{n=1}^{N}p_n^{-1/2}e^{i\theta_n(t)}
\right|^2dt
\le C\log\log p_N
$$

ここで $C$ は定数であり、十分大きな $N$ に対して評価される。

この Contract は意図的に弱い。これは零点排除定理ではなく、RH を含意しない。固定有限スケールにおける Provider 側の相殺挙動を隔離するだけである。

---

## 6. 依存性の隔離

Provider Contract は、より強い解析的仮定から意図的に隔離される。本仕様は、以下に依存しない。

1. $\zeta(s)$ の解析接続
2. リーマンの明示公式
3. 零点相関またはランダム行列統計
4. RH と同値またはそれに近い素数計数誤差項
5. Hilbert-Polya Hamiltonian などの作用素論的構成

この隔離こそが本仕様のアーキテクチャ上の価値である。これにより、証明アーキテクチャは次の問いを立てられる。

> 解析接続、明示公式、零点スペクトルを導入する前に、素数位相源だけから何を導けるか。

ILA の語彙では、Provider は Observer や Operator の責務を自身の Contract に密輸してはならない。

---

## 7. Mock Provider と注入戦略

Contract は有理数体上の一次独立性とトーラス一様分布で定義されるため、素数対数ではない mock 周波数ベクトルによっても検証できる。

たとえば、mock provider は次のような有限ベクトルを使うことができる。

$$
\omega=(\sqrt{2},\sqrt{3},\sqrt{5})
$$

または、有理数体上の一次独立性が示せる任意の有限族を用いることができる。

ただし、mock provider は係数重みも明示しなければならない。位相の一様分布だけでは、素数逆数和に対応するエネルギー評価は決まらない。Contract 3 の素数固有の評価は、重み $p_n^{-1/2}$ と素数逆数和の成長に依存する。非素数 mock の場合、対応する平均二乗エネルギーは、選択された係数 $a_n$ に対して

$$
\sum_{n=1}^{N}|a_n|^2
$$

となる。

Mock 注入は、以下に有用である。

- 位相雲の幾何学的検証
- Provider と Operator の仮定分離の検証
- 素数波動相転移の類似シミュレーション
- ゼータ零点仮定を持ち込まない Lean 条件付き補題の形式化

---

## 8. Use Cases

### 8.1 Lean による条件付き証明実験

Lean では、Provider を typeclass assumption として表現できる。定理は provider instance に相対化して述べられる。

```lean
import Mathlib

class UniformPhaseProvider (N : Nat) where
  freqs : Fin N -> Real
  linearIndependent : LinearIndependent Rat freqs
  -- equidistribution and cancellation bounds should be added
  -- incrementally as definitions or theorem assumptions.
```

これにより、依存境界が明示される。`UniformPhaseProvider N` だけを要求する定理は、RH と同値な誤差評価を、それが明示的な仮定として追加されない限り、暗黙に利用できない。

### 8.2 C# による Prime-wave シミュレーション

C# または他のシミュレーション環境では、`IUniformPhaseProvider` を、固定 $N$ と $t$ に対する位相ベクトルを供給するコンポーネントとして実装できる。後段のシミュレーションコードは、誘導される複素歩行を可視化し、経験的な位相分布を測定し、有限スケールのエネルギー挙動を検査できる。

シミュレーションでは、どの部分が Provider レベルであり、どの部分が Operator レベルであるかを明示しなければならない。位相生成は Provider に属する。Fourier / Mellin / Perron 変換は Operator に属する。統計的またはスペクトル的診断は Observer に属する。

### 8.3 明示公式 Bridge の前提条件

Provider Contract は明示公式そのものではない。これは後続の Bridge 構築のための前提条件である。Provider が独立かつ一様分布する位相を供給した後、Operator は重み付き素数信号をチェビシェフ関数、フォン・マンゴルト和、ペロン積分、零点スペクトル制約へ接続しようと試みることができる。

その Bridge がより強い評価を必要とする場合、その評価は Provider の内部に隠すのではなく、新しい Contract として宣言しなければならない。

---

## 9. Fail-Closed Behavior

本アーキテクチャは fail-closed である。

有理数体上の一次独立性が示されない場合、Provider Contract は失敗する。

一様分布性が利用できない、または非形式的に仮定されているだけの場合、Provider Contract は未完成である。

ある証明ステップが、Provider Contract だけを用いると主張しながら、解析接続、明示公式、零点相関、RH と同値な誤差評価を導入した場合、その証明インターフェースは失敗する。

Lean では、この原則は型レベルの規律となる。定理は、その定理文またはインポート済みコンテキストに含まれない仮定を使うことができない。通常の数学的記述においても、同じ規律を、すべての解析的仮定を明示列挙することで実現しなければならない。

---

## 10. Lean 形式化ノート

Lean 形式化は段階的に進めるべきである。

第一に、frequency provider と有理数体上の一次独立性を定義する。

```lean
import Mathlib

class UniformPhaseProvider (N : Nat) where
  freqs : Fin N -> Real
  linearIndependent : LinearIndependent Rat freqs
```

第二に、有限トーラスへの phase map を定義する。正確なトーラス表現は、商群、円値写像、または mathlib に存在する適切な構造を用いることができる。

第三に、equidistribution を Kronecker-Weyl 形式化から導く定理として追加するか、開発途中では明示的仮定として扱う。

第四に、二乗を展開し、非自明な時間平均が消えることを用いて固定スケールの平均二乗恒等式を証明する。

相殺上界は次の二層に分離すべきである。

1. 純粋な一様分布恒等式
2. $\sum_{p\le x}1/p$ に関する数論的評価

この分離により、位相一様性と素数逆数和の成長を混同することを防げる。

---

## 11. Prime-Wave 論文との関係

本仕様は、*Prime-Wave Phase Transition and Conditional Proof Interfaces: A Second Interface-Led Approach to the Riemann Hypothesis* の Section 4.1 に対応する。

同論文では、`IUniformPhaseProvider` が証明アーキテクチャにおける最初の分離可能な Contract として導入された。本稿はその節を独立仕様として展開する。本稿の役割は、将来の Lean 形式化と数値実験を支えるために、Provider 側の仮定を十分明示的にすることである。

対応関係は次の通りである。

| Prime-Wave 論文 | 本仕様 |
|---|---|
| provider contract を導入する | 独立した interface として定義する |
| 位相一様性を proof boundary として扱う | Contract requirements として明示する |
| ILA によって証明義務を分解する | その一つに対する形式 Contract を与える |
| mock-provider 実験を識別する | 注入戦略と限界を定義する |

---

## 12. Limitations and Non-Claims

本仕様は RH を証明しない。

また、素数波動相転移モデルが零点排除へ接続できることも証明しない。その接続には、明示公式 Bridge、非循環的誤差評価、および極限操作の一様制御が必要である。

本 Contract は有限スケールである。$T\to\infty$ を取る前に $N$ を固定する。$N$ と $T$ の両方に一様な評価は含まれておらず、将来の proof obligation として扱われるべきである。

Mock provider モデルはアーキテクチャのテストには有用であるが、係数重みや成長法則を指定しない限り、算術的な素数挙動を再現するものではない。

最後に、Lean スケッチは完成済み形式化ではない。これは、仮定をどこへ配置すべきかを示す最小インターフェースの輪郭である。

---

## 13. Conclusion

`IUniformPhaseProvider` は、素数波動 RH 研究プログラムが必要とする最弱の Provider 側位相 Contract を隔離する。有理数体上の一次独立性、トーラス一様分布、固定スケール平均二乗相殺を、解析接続、明示公式、零点相関、RH と同値な誤差評価から分離することにより、本仕様は将来の条件付き証明とシミュレーションのための清潔な境界を形成する。

このインターフェースの価値は、リーマン予想を証明することではない。その価値は、証明試行が Provider、Observer、Operator の責務を暗黙に混在させることを防ぐ点にある。これにより、素数波動証明アーキテクチャは、最小で、検証可能で、fail-closed な出発点を得る。

---

## References

1. Weyl, Hermann. "Über die Gleichverteilung von Zahlen mod. Eins." *Mathematische Annalen*, vol. 77, 1916, pp. 313-352. DOI: 10.1007/BF01475864.
2. Titchmarsh, E. C. *The Theory of the Riemann Zeta-Function*. 2nd ed., revised by D. R. Heath-Brown, Oxford University Press, 1986.
3. Davenport, Harold. *Multiplicative Number Theory*. 3rd ed., revised by Hugh L. Montgomery, Springer, 2000.
4. The mathlib Community. "The Lean Mathematical Library." *Proceedings of the 9th ACM SIGPLAN International Conference on Certified Programs and Proofs*, 2020. DOI: 10.1145/3372885.3373824.
5. Sogawa, Takuya. "Interface-Led Architecture (ILA): A Software Development Methodology for the AI Era, Validated by the AIKernel Execution Model." Zenodo, 2026. DOI: 10.5281/zenodo.20290614.
6. Sogawa, Takuya. "Provider-Observer-Operator: A Role-Based Abstraction Discipline for Interface-Led Architecture." Zenodo, 2026. DOI: 10.5281/zenodo.20322690.
7. Sogawa, Takuya. "Prime-Wave Phase Transition and Conditional Proof Interfaces: A Second Interface-Led Approach to the Riemann Hypothesis." Zenodo, 2026. DOI: 10.5281/zenodo.20357202.
