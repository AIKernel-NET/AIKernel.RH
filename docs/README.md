# AIKernel Research Documentation  
### ILA Architecture / Prime Phase Generation System / Formal Lean 4 Models  
**Author:** Takuya Sogawa 
**Updated:** 2026-05-26

---

## Overview

この `docs/` ディレクトリは、AIKernel / ILA / Prime Phase Generation System に関する  
**論文・研究ノート・設計文書・図表・実験ログ**を体系的にまとめた総合ドキュメント領域です。

構成は以下の3層に分かれています：

1. **Theory Layer（理論層）**  
   - ILA（Interface-Led Architecture）  
   - Phase-Dynamical Number Theory  
   - Prime Phase Generation System（PPGS）  
   - Prompt-State Machine / Semantic Runtime

2. **Formalization Layer（形式化層）**  
   - Lean 4 による数学的形式化  
   - Primegenerator モジュール  
   - 位相基底・干渉エネルギー・局所場・安定固定点の定義

3. **Publication Layer（論文層）**  
   - Zenodo 公開論文  
   - PDF / Markdown / 図表  
   - 研究成果のアーカイブ

---

## Directory Structure


```
docs/ 
├── diagrams/ ← 図表・構造図 
│ ├── architecture.svg 
│ └── phase-diagram.svg 
├── paper/ ← 論文群（Zenodo 公開仕様） 
│ ├── ila_riemann_governance_v0_1_0/ 
│ ├── ila_riemann_prime_wave_phase_transition_v0_1_0/ 
│ └── iuniform_phase_provider_specification_v0_1_0/ 
├── research-notes/ ← 研究ノート（理論・実装ログ） 
│ ├── 2026-05-26-lean-setup.md 
│ ├── prime-phase-generation-system.md 
│ └── ILA-architecture.md (予定) 
└── README.md ← このファイル
```

---

##  Papers（論文）

Zenodo 公開仕様に準拠した正式論文群。  
各フォルダには `.zenodo.json`, `CITATION.cff`, `LICENSE`, `metadata-zenodo.md` が含まれます。

| 論文名 | 概要 | 言語 | DOI / Version |
|---------|------|------|----------------|
| **ila_riemann_governance_v0_1_0** | ILA のガバナンス構造とリーマン的位相空間の統合 | EN / JA | v0.1.0 |
| **ila_riemann_prime_wave_phase_transition_v0_1_0** | Prime-Wave の位相遷移モデル | EN / JA | v0.1.0 |
| **iuniform_phase_provider_specification_v0_1_0** | UniformPhaseProvider の仕様定義 | EN / JA | v0.1.0 |

---

##  Research Notes（研究ノート）

理論構築・Lean 実装・実験記録をまとめたノート群。

### **1. Lean 4 Formalization Log**  
`research-notes/2026-05-26-lean-setup.md`  
Lean プロジェクト構築、mathlib 導入、モジュール階層、ビルド成功までの記録。

### **2. Prime Phase Generation System — Formal Specification**  
`research-notes/prime-phase-generation-system.md`  
位相基底、干渉エネルギー、局所場、安定固定点、核心命題の定義。

### **3. ILA Architecture（予定）**  
`research-notes/ILA-architecture.md`  
Provider / Observer / Operator の抽象構造と Primegenerator との関係。

---

##  Experiments（予定）

- Lean 4 による prime-wave operator の実験  
- σₜ(n) の動的位相モデル  
- 干渉エネルギーの可視化  
- 素数分布の位相的解析  

---

##  Theory（予定）

- 位相的数論（Phase-Dynamical Number Theory）  
- Prime-Wave Operator の数学的定義  
- ILA と数論の統合モデル  
- Radix Residue Filter / UniformPhaseProvider の理論背景  

---

##  Roadmap

- [ ] prime-wave operator の導入  
- [ ] σₜ(n) の動的位相モデル（Dynamics）  
- [ ] 干渉エネルギーの本物の定義に置き換え  
- [ ] `prime_iff_stable_fixed_point` の構成的証明  
- [ ] ILA Architecture 文書の追加  
- [ ] Zenodo への研究ノート公開  

---

##  Purpose

このドキュメント群は、  
**AIKernel / ILA / Prime Phase Generation System の理論的基盤を体系化し、  
Lean 4 による形式化を通じて数学的に検証可能な形にすること**
を目的としています。
