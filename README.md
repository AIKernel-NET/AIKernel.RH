# AIKernel.RH
Interface-Led Architecture for the Riemann Hypothesis リーマン予想のためのインターフェース主導アーキテクチャ
---
## Overview / 概要

**AIKernel.RH** is a research repository that applies **Interface-Led Architecture (ILA)** to the mathematical structure of the **Riemann Hypothesis (RH)**.

This project provides:

- A **formal proof architecture** in Lean 4
    
- **Numerical experiments** in C# (Prime-wave / Phase-transition model)
    
- **Specifications and papers** describing the ILA approach to RH
    
- A minimal mathematical contract: **IUniformPhaseProvider**
    

**AIKernel.RH** は、 **Interface-Led Architecture（ILA）** を数学へ適用し、 **リーマン予想（RH）をアーキテクチャとして再定義する**研究リポジトリです。

本プロジェクトは以下を提供します：

- Lean 4 による **形式的証明アーキテクチャ**
    
- C# による **素数波動・相転移モデルの数値実験**
    
- ILA に基づく RH 研究の **仕様書・論文**
    
- 最小の数学的契約：**IUniformPhaseProvider**
    

## Purpose / 目的

Traditional approaches to the Riemann Hypothesis treat it as a monolithic analytic problem. AIKernel.RH instead decomposes RH into **interfaces**, **contracts**, and **proof obligations**, following the principles of ILA and system governance.

This repository aims to:

- Separate **Provider / Observer / Operator / Contract** roles
    
- Formalize the minimal contract for prime-phase behavior
    
- Provide a Lean-based **Fail-Closed proof architecture**
    
- Enable reproducible experiments for prime-wave dynamics
    
- Bridge numerical intuition and formal proof
    

従来のリーマン予想研究は巨大なモノリスとして扱われてきました。 AIKernel.RH はこれを **インターフェースと契約に分解**し、 ILA とシステムガバナンスの原則に基づいて再構成します。

本リポジトリの目的：

- **Provider / Observer / Operator / Contract** の責務分離
    
- 素数位相の最小契約の形式化
    
- Lean による **Fail-Closed 型の証明アーキテクチャ**
    
- 素数波動モデルの再現可能な数値実験
    
- 数値的直感と形式的証明の橋渡し
    

## Repository Structure / リポジトリ構成

コード

```
AIKernel.RH/
│
├── README.md
├── LICENSE
│
├── docs/                     ← Papers & specifications (CC-BY-4.0)
│   ├── paper/
│   │   ├── prime-wave-phase-transition-ja.md
│   │   ├── prime-wave-phase-transition-en.md
│   │   └── uniform-phase-provider-spec.md
│   └── diagrams/
│       ├── architecture.png
│       └── phase-diagram.png
│
├── lean/                     ← Lean 4 formal proof architecture (MIT)
│   ├── lakefile.lean
│   ├── lean-toolchain
│   ├── ILA/
│   │   ├── UniformPhaseProvider.lean
│   │   ├── Equidistribution.lean
│   │   ├── CancellationBound.lean
│   │   └── ConditionalProofInterface.lean
│   └── Tests/
│       └── MockProvider.lean
│
├── csharp/                   ← Numerical experiments (MIT)
│   ├── AIKernel.RH.sln
│   ├── PrimeWave/
│   │   ├── PrimeWaveSimulator.cs
│   │   ├── TorusOrbitPlot.cs
│   │   └── EnergyPhaseDiagram.cs
│   └── Experiments/
│       ├── MockProviderExperiment.cs
│       └── UniformPhaseExperiment.cs
│
└── scripts/                  ← Optional automation
    ├── generate-plots.py
    └── run-experiments.sh
```

##  Core Concept: IUniformPhaseProvider

### _素数位相の最小契約（Contract）_

This project introduces a minimal mathematical interface:

コード

```
interface IUniformPhaseProvider
```

It defines:

- Prime-mode frequencies
    
- Q-linear independence
    
- Asymptotic equidistribution on the N-torus
    
- Minimal cancellation bound (log log N)
    

This contract isolates prime-phase behavior from:

- Analytic continuation
    
- Zero correlations
    
- Explicit formula assumptions
    
- RH-equivalent error terms
    

本プロジェクトの中心は、数学的最小契約：

コード

```
IUniformPhaseProvider
```

これにより、素数位相の振る舞いを以下から完全に隔離します：

- 解析接続
    
- 零点相関
    
- 明示公式の仮定
    
- RH 同値の誤差項
    

##  Numerical Experiments / 数値実験

The C# implementation provides:

- Prime-wave simulation
    
- Torus orbit visualization
    
- Phase-transition diagrams
    
- Mock Provider injection tests
    

C# 実装では以下を提供します：

- 素数波動シミュレーション
    
- トーラス軌道の可視化
    
- 相転移ダイアグラム
    
- Mock Provider による契約検証
    

##  Formal Proof Architecture (Lean 4)

### _形式的証明アーキテクチャ（Lean 4）_

The Lean project formalizes:

- The IUniformPhaseProvider contract
    
- Equidistribution requirements
    
- Cancellation bounds
    
- Conditional Proof Interface
    
- Fail-Closed proof boundaries
    

This enables a **machine-verifiable architecture** for future RH research.

Lean プロジェクトでは以下を形式化します：

- IUniformPhaseProvider 契約
    
- 一様分布要件
    
- 相殺バウンド
    
- 条件付き証明インターフェース
    
- Fail-Closed 証明境界
    

これにより、**機械検証可能な証明アーキテクチャ**が構築されます。

##  License / ライセンス

- **docs/** → CC-BY-4.0
    
- **lean/** → MIT
    
- **csharp/** → MIT
    

##  Contributions / コントリビューション

Contributions are welcome in:

- Lean formalization
    
- Numerical experiments
    
- Documentation
    
- Visualization
    
- Mathematical analysis
    

## 🌟 Author / 著者

**Takuya Sogawa** AIKernel.NET ORCID: 0009-0009-7499-2595
