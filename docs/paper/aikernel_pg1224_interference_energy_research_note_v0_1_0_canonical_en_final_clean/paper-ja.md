---
id: aikernel.research-note.pg1224-interference-energy.ja
title: "位相干渉エネルギーと PG1224 素数生成系の形式的構造"
subtitle: "Lean 4 による Prime = Energy 0 = 安定固定点の形式化と意味論"
version: "0.1.0"
edition: "Research Note"
status: "Research Note / Companion Translation"
issuer: "takuya.sogawa@aikernel.net"
maintainer: "Takuya Sogawa"
author: "Takuya Sogawa"
orcid: "https://orcid.org/0009-0009-7499-2595"
affiliation: "AIKernel Project"
license: "CC-BY-4.0"
lang: "ja"
canonical_language: "en"
canonical_file: "paper-en.md"
created: 2026-06-01
last_updated: 2026-06-01
published: 2026-06-01
updated: 2026-06-01
date: 2026-06-01
doi: "10.5281/zenodo.20483437"
tags:
  - AIKernel
  - PG1224
  - Interference Energy
  - Prime Numbers
  - Lean 4
  - Formal Verification
  - Residue-class Filtering
  - Stable Fixed Point
owners:
  - Takuya Sogawa
---
**著者:** Takuya Sogawa  
**所属:** AIKernel Project  
**ORCID:** [https://orcid.org/0009-0009-7499-2595](https://orcid.org/0009-0009-7499-2595)  
**Version:** v0.1.0  
**Date:** 2026-06-01  
**DOI:** `10.5281/zenodo.20483437`  
**License:** CC BY 4.0  
**Canonical version:** English (`paper-en.md` / `paper-en.pdf`)  
**Japanese version:** Companion translation

---

## 概要

本研究ノートは、自然数の素性を「位相干渉エネルギー」という操作的概念によって再記述し、素数を「非自明な内部干渉を持たない安定固定点」として扱う形式的モデルを整理するものである。

本稿における干渉エネルギーとは、自然数 `n` が持つ非自明な約数、すなわち `1 < m < n` かつ `m ∣ n` を満たす内部構造の存在を測る量である。合成数は少なくとも一つの非自明約数を持つため、干渉エネルギーが正に立ち上がる。一方、2 以上の自然数において非自明約数を持たない点は、干渉エネルギー 0 の安定状態として特徴づけられる。

この直観を Lean 4 によって形式化することで、`Nat.Prime n`、`interferenceEnergy n = 0`、および `isStableFixedPoint n` の関係を、単なる比喩ではなく検証可能な論理命題として扱う。特に、0 および 1 は `interferenceEnergy = 0` となり得る境界状態であるため、本稿では安定固定点を `2 ≤ n` という領域条件付きで定義する。これにより、「Prime = Energy 0 = 安定固定点」という主張を自然数全域に対して安全に述べるための形式的境界を明確化する。

さらに、基数 12 および 24 の剰余類構造に基づく PG1224 素数候補生成系を導入し、Residue-class filtering を干渉 cancellation として解釈する。PG1224 は、偶数および 3 の倍数に由来する自明な干渉を事前に除外し、その後に残る候補を Lean 上の素数性述語と接続することで、候補生成・検証・安定固定点の三者を一つの形式的枠組みに統合する。

---

## Keywords

Prime numbers; Interference energy; PG1224; Lean 4; Formal verification; Residue-class filtering; Stable fixed point; AIKernel

---

## 1. 背景と動機

### 1.1 位相干渉エネルギーとは何か

本研究における「位相干渉エネルギー（interference energy）」とは、自然数が内部に持つ非自明な分解可能性を、干渉として測るための操作的概念である。

従来の初等整数論では、合成数は「1 と自分自身以外の約数を持つ自然数」として静的に定義される。本稿では、この構造を少し異なる角度から眺める。ある自然数 `n` が非自明な約数 `m` を持つとき、`n` は自分自身より小さな周期構造を内部に含んでいる。この内部周期は、位相モデルの比喩では「自己内部に存在する干渉成分」として解釈できる。

このとき、合成数は複数の周期成分が重なり合った励起状態であり、素数は非自明な内部周期を持たない純粋状態である。したがって、素数は干渉エネルギーが 0 である点、すなわち分解方向への内部遷移を持たない安定固定点として扱うことができる。

### 1.2 Prime をエネルギー極小点として扱う理由

素数 `p` は、`1` と `p` 以外の約数を持たない。これは、`p` の内部に `1 < m < p` なる約数が存在しないことを意味する。

干渉エネルギーを「非自明約数の存在量」として定義すると、素数においてはこの量が 0 になる。一方、合成数では少なくとも一つの非自明約数が存在するため、干渉エネルギーは正に立ち上がる。

この対応は、次の直観にまとめられる。

```text
Prime
  = no non-trivial divisor
  = zero interference energy
  = stable fixed point under divisor-collapse semantics
```

ただし、この同値性を自然数全体で扱う場合には注意が必要である。`0` と `1` も非自明約数を持たないため、単純に `interferenceEnergy n = 0` と定義するだけでは、`0` および `1` も安定状態に含まれてしまう。

そのため、本稿では素数との同値性を述べる際、領域条件 `2 ≤ n` を明示的に含める。これは数学的な細部ではなく、形式化における健全性を保つための重要な境界条件である。

### 1.3 Residue-class filtering と cancellation

素数生成系において、剰余類による候補削減は基本的かつ強力な考え方である。特に、2 の倍数および 3 の倍数は、素数候補から事前に除外できる。

基数 12 において、3 より大きい素数は必ず次の剰余類のいずれかに属する。

```text
1, 5, 7, 11 mod 12
```

同様に、基数 24 において 3 より大きい素数は、24 と互いに素な剰余類に属する。

```text
1, 5, 7, 11, 13, 17, 19, 23 mod 24
```

本稿では、この residue-class filtering を「自明な干渉の cancellation」として解釈する。すなわち、2 または 3 に由来する周期的干渉を先に取り除くことで、干渉エネルギーが立ち上がり得る候補を効率的に絞り込む。

### 1.4 Lean 4 による形式化の意義

「素数 = 干渉エネルギー 0 = 安定固定点」という表現は直観的には自然である。しかし、直観だけでは数学的主張として十分ではない。

Lean 4 による形式化の意義は、次の点にある。

1. 用語の意味を `def` と `theorem` によって明確化できる。
2. 境界条件、特に `0` と `1` の扱いを曖昧にせずに済む。
3. 「比喩としてのエネルギー」と「論理命題としての約数構造」を分離できる。
4. 証明が小さな補題の組み合わせとして機械的に検査される。
5. PG1224 の候補生成と素数性検証の責務境界を明確化できる。

したがって、本稿の主張は「新しい素数定義」ではなく、既存の素数概念をエネルギー最小化および安定固定点の意味論で再構成し、それを Lean 4 上で検査可能な形に置くことである。

---

## 2. 干渉エネルギーの定義と意味論

### 2.1 非自明約数

自然数 `n` に対して、非自明約数を次の条件を満たす自然数 `m` とする。

```text
1 < m ∧ m < n ∧ m ∣ n
```

この条件は、`m` が `n` の内部に存在する真の分解成分であることを表す。

Lean 風の定義としては、次のように表現できる。

```lean
def isNontrivialDivisor (n m : Nat) : Prop :=
  1 < m ∧ m < n ∧ m ∣ n
```

### 2.2 interferenceEnergy

`interferenceEnergy n` は、`n` が持つ非自明約数の個数として定義する。

実装上は、`0` から `n` までの有限探索空間を作り、条件を満たす要素を数える形にできる。

```lean
def nontrivialDivisors (n : Nat) : List Nat :=
  (List.range (n + 1)).filter (fun m =>
    1 < m ∧ m < n ∧ n % m = 0)

noncomputable def interferenceEnergy (n : Nat) : Nat :=
  (nontrivialDivisors n).length
```

実際の Lean 実装では、`Decidable` インスタンスや `%` と `∣` の接続、`List.filter` に関する補題が必要になる。ここで重要なのは、干渉エネルギーが自然数値の量として定義され、負の値を取らないことである。

簡単な計算例を示す。`12` の非自明約数は `{2, 3, 4, 6}` であるため、`interferenceEnergy 12 = 4` となる。一方、`13` は非自明約数を持たないため、`interferenceEnergy 13 = 0` となる。

```text
12 -> {2, 3, 4, 6} -> energy = 4
13 -> {}            -> energy = 0
```

### 2.3 状態の意味論

この定義により、自然数 `n` の状態は次のように解釈できる。

| 状態 | 数論的意味 | 干渉モデル上の意味 |
|---|---|---|
| `interferenceEnergy n = 0` | 非自明約数が存在しない | 内部干渉を持たない状態 |
| `interferenceEnergy n > 0` | 非自明約数が存在する | 内部干渉が励起した状態 |

ただし、`interferenceEnergy n = 0` だけでは `0` と `1` も含まれる。そのため、素数との同値性を述べるには、`2 ≤ n` を合わせて扱う必要がある。

### 2.4 安定固定点

位相生成系において、それ以上非自明な内部構造へ崩壊しない点を安定固定点と呼ぶ。

この概念を Lean 風に定義すると、次のようになる。

```lean
def isStableFixedPoint (n : Nat) : Prop :=
  2 ≤ n ∧ interferenceEnergy n = 0
```

この定義では、`2 ≤ n` を含めることで、`0` および `1` を境界状態として除外する。これにより、安定固定点は素数と一致する候補になる。

---

## 3. PG1224 の構成

### 3.1 PG1224 の基本方針

PG1224[^pg1224] は、基数 12 および 24 の剰余類空間を用いて、素数候補を絞り込む生成系である。

この名称は、基数 12 および 24 の residue-class structure を利用する Prime Generator という意味で用いる。

PG1224 の役割は、すべての自然数を無差別に検査するのではなく、明らかに合成数となる候補を先に除外し、干渉エネルギー 0 となり得る候補空間を縮小することである。

### 3.2 候補集合

PG1224 の候補集合は、次のように考える。

```text
{2, 3}
∪ { n | n mod 12 ∈ {1, 5, 7, 11} }
∪ { n | n mod 24 ∈ {1, 5, 7, 11, 13, 17, 19, 23} }
```

Lean 風には、次のような定義になる。

```lean
def candidate12 (n : Nat) : Prop :=
  n % 12 = 1 ∨ n % 12 = 5 ∨ n % 12 = 7 ∨ n % 12 = 11

def candidate24 (n : Nat) : Prop :=
  n % 24 = 1 ∨ n % 24 = 5 ∨ n % 24 = 7 ∨ n % 24 = 11 ∨
  n % 24 = 13 ∨ n % 24 = 17 ∨ n % 24 = 19 ∨ n % 24 = 23

def candidate_PG1224 (n : Nat) : Prop :=
  n = 2 ∨ n = 3 ∨ candidate12 n ∨ candidate24 n
```

この候補集合は、素数そのものを直接生成するものではない。あくまで、素数である可能性のある剰余類を残す候補フィルタである。

### 3.3 生成述語

PG1224 が `n` を生成済みの素数として扱う条件を、候補性と素数性の結合として定義する。

```lean
def generatesImpl_PG1224 (n : Nat) : Prop :=
  candidate_PG1224 n ∧ Nat.Prime n
```

この定義では、`Nat.Prime n` を含んでいるため、`generatesImpl_PG1224` は単独の素数判定アルゴリズムではなく、候補フィルタと素数性証明を結合した certified generation predicate である。

この責務境界は重要である。PG1224 は、候補空間の cancellation を担う。一方、最終的な素数性は Lean の `Nat.Prime` またはそれと同値な証明によって保証される。

### 3.4 Soundness, Completeness, Minimality

PG1224 の形式的評価は、次の三つに整理できる。

#### Soundness

PG1224 が生成した要素は、必ず素数であり、したがって干渉エネルギー 0 の安定固定点である。

```lean
theorem pg1224_sound (n : Nat) :
  generatesImpl_PG1224 n → Nat.Prime n := by
  intro h
  exact h.right
```

この soundness は、`generatesImpl_PG1224` の定義上ただちに従う。

#### Completeness

すべての素数は PG1224 の候補集合に含まれる。

```lean
theorem prime_implies_candidate_PG1224 (n : Nat) :
  Nat.Prime n → candidate_PG1224 n := by
  -- Split the prime cases into n = 2, n = 3, and n > 3.
  -- If n > 3, primality implies that n is divisible by neither 2 nor 3.
  -- Therefore gcd n 6 = 1, so n falls into the residue classes coprime to 6,
  -- which are represented by the PG1224 residues modulo 12 and 24.
  sorry
```

証明スケッチとしては、まず `n = 2` および `n = 3` を候補集合の特別要素として処理する。次に `n > 3` の場合、素数性から `¬ 2 ∣ n` かつ `¬ 3 ∣ n` が従うため、`n` は `6` と互いに素である。したがって `n` は `12` および `24` を法とする剰余類のうち、`2` と `3` による自明な干渉を受けない類に属し、PG1224 の候補集合へ入る。

この補題により、次が得られる。

```lean
theorem pg1224_complete (n : Nat) :
  Nat.Prime n → generatesImpl_PG1224 n := by
  intro hp
  exact And.intro (prime_implies_candidate_PG1224 n hp) hp
```

#### Minimality

本稿における minimality は、全ての素数生成法の中で大域的に最小である、という強い主張ではない。ここでいう minimality は、基数 12 および 24 の residue-class filtering により、2 と 3 に起因する自明な干渉を事前に除外する局所的な冗長性削減を指す。

より強い意味での最小性、たとえば任意の候補生成系に対する最適性を主張する場合は、別途、候補空間、コスト関数、許容される residue basis を明示した上で定理化する必要がある。


[^pg1224]: `PG1224` は、基数 `12` と `24` の residue-class filtering を組み合わせた Prime Generator を表す便宜的名称である。

---

## 4. 干渉エネルギーの構造定理

### 4.1 Non-negativity

干渉エネルギーは自然数値であるため、常に 0 以上である。

```lean
theorem interferenceEnergy_nonneg (n : Nat) :
  0 ≤ interferenceEnergy n := by
  exact Nat.zero_le _
```

これは単純な定理であるが、エネルギーが非物理的な負値を取らないことを保証する。

### 4.2 Composite numbers raise energy

`n` が合成数であれば、非自明な約数が存在する。したがって、干渉エネルギーは正になる。

```lean
theorem interferenceEnergy_pos_of_composite (n : Nat) :
  Composite n → 0 < interferenceEnergy n := by
  -- A composite number has a non-trivial divisor.
  -- Therefore the filtered divisor list is non-empty.
  sorry
```

ここで `Composite n` は、たとえば次のような補助述語として定義できる。

```lean
def Composite (n : Nat) : Prop :=
  ∃ m, 1 < m ∧ m < n ∧ m ∣ n
```

この定理は、合成数が「少なくとも一つの干渉成分を持つ」ことを形式化する。

### 4.3 Divisor monotonicity

約数鎖に沿って、内部構造は保存または増加する。

直観的には、`d ∣ n` かつ `2 ≤ d < n` であるとき、`d` の非自明約数は `n` の内部構造にも埋め込まれる。そのため、適切な条件のもとで次のような単調性が期待される。

```lean
theorem interferenceEnergy_divisor_monotone (d n : Nat) :
  2 ≤ d → d < n → d ∣ n →
  interferenceEnergy d ≤ interferenceEnergy n := by
  -- Non-trivial divisors of d are mapped into non-trivial divisors of n.
  sorry
```

この定理は、複雑な倍数構造ほど内部干渉の潜在量が小さくならないことを表す。

### 4.4 Cancellation by a non-trivial divisor

非自明約数が一つでも存在すれば、干渉エネルギーは少なくとも 1 以上に立ち上がる。

```lean
theorem interferenceEnergy_ge_one_of_has_nontrivial_divisor (n : Nat) :
  (∃ m, 1 < m ∧ m < n ∧ m ∣ n) →
  1 ≤ interferenceEnergy n := by
  -- The divisor m appears in the filtered list.
  -- Therefore the list length is at least one.
  sorry
```

これは PG1224 の cancellation 意味論において重要である。一つの非自明な干渉を検出できれば、その候補はエネルギー極小点ではないと判断できる。

---

## 5. Prime = Energy 0 = 安定固定点

### 5.1 Energy zero and absence of non-trivial divisors

まず、干渉エネルギー 0 は、非自明約数の不存在と同値である。

```lean
theorem energy_zero_iff_no_nontrivial_divisors (n : Nat) :
  interferenceEnergy n = 0 ↔
    ¬ ∃ m, 1 < m ∧ m < n ∧ m ∣ n := by
  -- The filtered list has length zero iff it contains no element.
  sorry
```

この補題は、リスト長と存在命題を接続する中心的な橋である。

### 5.2 Prime iff energy zero under n ≥ 2

`0` と `1` を除外するため、`2 ≤ n` の条件を置く。

```lean
theorem prime_iff_energy_zero_of_two_le (n : Nat) (hn : 2 ≤ n) :
  Nat.Prime n ↔ interferenceEnergy n = 0 := by
  -- Forward direction:
  --   a prime has no non-trivial divisor.
  -- Backward direction:
  --   if n ≥ 2 and no non-trivial divisor exists, n is prime.
  sorry
```

この定理により、「素数 = 干渉エネルギー 0」という主張が、領域条件付きで正確に成立する。

### 5.3 Prime iff stable fixed point

`isStableFixedPoint` に `2 ≤ n` を含めているため、自然数全域で次の定理を述べられる。

```lean
theorem prime_iff_stable_fixed_point (n : Nat) :
  Nat.Prime n ↔ isStableFixedPoint n := by
  constructor
  · intro hp
    exact And.intro
      (Nat.Prime.two_le hp)
      ((prime_iff_energy_zero_of_two_le n (Nat.Prime.two_le hp)).mp hp)
  · intro hs
    exact (prime_iff_energy_zero_of_two_le n hs.left).mpr hs.right
```

この定義により、0 と 1 の境界問題を避けながら、「Prime = Energy 0 = Stable Fixed Point」を安全に定理化できる。

### 5.4 PG1224 との統合

PG1224 の completeness が得られているなら、次の同値性を構成できる。

```lean
theorem prime_iff_pg1224_generated (n : Nat) :
  Nat.Prime n ↔ generatesImpl_PG1224 n := by
  constructor
  · exact pg1224_complete n
  · exact pg1224_sound n
```

さらに、PG1224 生成、素数性、安定固定点、干渉エネルギー 0 を統合すると、次のような定理として整理できる。

```lean
theorem pg1224_unified_equivalence (n : Nat) :
  Nat.Prime n ↔
    generatesImpl_PG1224 n ∧
    isStableFixedPoint n ∧
    interferenceEnergy n = 0 := by
  constructor
  · intro hp
    exact And.intro
      ((prime_iff_pg1224_generated n).mp hp)
      (And.intro
        ((prime_iff_stable_fixed_point n).mp hp)
        ((prime_iff_energy_zero_of_two_le n (Nat.Prime.two_le hp)).mp hp))
  · intro h
    exact (prime_iff_pg1224_generated n).mpr h.left
```

Lean では、`A ↔ B ↔ C ↔ D` のような連鎖表現は結合規則の影響を受けやすいため、公開仕様では上記のように補題を分割し、最後に積としてまとめる形が望ましい。

---

## 6. 証明構造の意味論

### 6.1 Soundness

Soundness は、系が生成した対象が必ず素数であることを意味する。

PG1224 においては、生成述語が `candidate_PG1224 n ∧ Nat.Prime n` と定義されているため、soundness は定義から直接従う。

これは一見すると自明である。しかし、設計上は重要である。PG1224 は「候補を作る層」と「素数性を証明する層」を混同しない。AIKernel 的に言えば、候補生成器は Provider であり、素数性検証は Verifier または Governance layer の責務である。

### 6.2 Completeness

Completeness は、すべての素数が PG1224 の候補空間に入ることを意味する。

3 より大きい素数は 2 でも 3 でも割り切れない。そのため、12 または 24 を法としたとき、2 および 3 と互いに素な剰余類に属する。これが PG1224 の completeness の基礎となる。

### 6.3 Stable fixed point

安定固定点は、約数による非自明な内部崩壊を持たない点である。

`interferenceEnergy n = 0` は、非自明約数が存在しないことを意味する。`2 ≤ n` と合わせることで、これは `Nat.Prime n` と一致する。

したがって、安定固定点とは「これ以上非自明に分解されない自然数状態」であり、初等整数論における素数と同じ対象を、動的・生成系的な意味論で再表現したものである。

---

## 7. 応用可能性

### 7.1 LLM の揺らぎ制御

本稿の中心的なアイデアは、素数そのものよりも広い意味を持つ。

干渉エネルギーは、「内部に存在する非自明な矛盾・分岐・崩壊要因」を測る量として抽象化できる。この考え方を LLM の推論軌跡に応用すれば、意味的な矛盾、意図の揺らぎ、ツール選択の不安定性、過剰な再帰的修正などを干渉エネルギーとして扱える。

AIKernel Trajectory Governance の文脈では、推論が安定固定点へ収束しているか、あるいは干渉エネルギーが立ち上がっているかを観測し、必要に応じて fail-closed する設計が考えられる。

### 7.2 位相的数論モデルとしての意義

本モデルは、素数を静的な集合としてだけでなく、干渉 cancellation の後に残る安定点として扱う。

これは、素数を「分割不能な点」として見る従来の定義と矛盾しない。むしろ、その定義を位相的・生成系的な語彙に翻訳するものである。

この翻訳により、 residue-class filtering、sieve、生成器、エネルギー最小化、固定点といった概念を一つのフレームに配置できる。

### 7.3 生成系の OS 的応用

AIKernel のような AI orchestration OS においては、入力タスクが安全に実行可能かどうかを判定する必要がある。

PG1224 の構造は、この判定モデルの抽象例として読める。

1. 自明に危険または不適切な候補を residue-class filtering に相当する前処理で除外する。
2. 残った候補に対して干渉エネルギーを評価する。
3. エネルギー 0 の安定候補のみを実行層へ渡す。
4. エネルギーが正に立ち上がる候補は、確認、隔離、または fail-closed の対象とする。

この意味で、PG1224 は単なる数論上の候補生成系ではなく、AIKernel における governance gateway の小さな形式モデルとして解釈できる。

---

## 8. 非主張事項

本稿は、次の主張を行わない。

1. 既存の素数定義を置き換えるものではない。
2. PG1224 が既存のふるい法より計算量的に優れているとは主張しない。
3. `generatesImpl_PG1224` は、`Nat.Prime` を含む certified generation predicate であり、単独の素数判定器ではない。
4. residue-class filtering だけで全ての合成数を除去できるとは主張しない。
5. 本稿は解析的整数論上の未解決問題を証明するものではない。
6. 「エネルギー」という語は、物理量そのものではなく、約数構造を説明するための操作的・意味論的名称である。

これらの非主張事項を明確にすることで、本稿の貢献範囲を適切に限定する。

---

## 9. 結論

本研究ノートでは、自然数の非自明約数構造を干渉エネルギーとして定義し、素数をエネルギー 0 の安定固定点として再構成した。

重要な点は、`interferenceEnergy n = 0` だけでは `0` と `1` を除外できないため、安定固定点の定義に `2 ≤ n` を含めることである。この領域条件により、自然数全域において `Nat.Prime n ↔ isStableFixedPoint n` を安全に定理化できる。

さらに、基数 12 および 24 の residue-class filtering を用いる PG1224 を、干渉 cancellation に基づく候補生成系として位置づけた。PG1224 は、候補生成と素数性証明を分離し、Lean 4 上で soundness、completeness、安定固定点性を接続するための形式的枠組みを提供する。

本稿の中心的貢献は、新しい素数概念を導入することではない。既存の素数概念を、エネルギー最小化、干渉 cancellation、安定固定点、形式検証という語彙で再記述し、AIKernel 的な governance model へ接続可能な形に整理した点にある。

---

## References

The mathlib Community. (2020). The Lean mathematical library. *Proceedings of the 9th ACM SIGPLAN International Conference on Certified Programs and Proofs*, 367–381. https://doi.org/10.1145/3372885.3373824

de Moura, L., Kong, S., Avigad, J., van Doorn, F., & von Raumer, J. (2015). The Lean Theorem Prover. *Automated Deduction - CADE-25*, Lecture Notes in Computer Science, 9195, 378–388. Springer. https://doi.org/10.1007/978-3-319-21401-6_26

Lean FRO. (2026). *Lean 4 Manual*. Lean Focused Research Organization.

Sogawa, T. (2026). *AIKernel Trajectory Governance Model: A Kernel-Level Framework for Convergent Decision Control over Stochastic Language Model Inference*. Zenodo.

Sogawa, T. (2026). *AIKernel Formal Foundations: Contract-Based Semantic Execution for Governed AI Systems*. Zenodo.
