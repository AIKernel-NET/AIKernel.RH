---
id: numbertheory.contract.uniform-phase.en
title: "IUniformPhaseProvider Specification: A Minimal Contract for Independent Prime-Phase Generators"
version: 0.1.0
status: canonical-draft
issuer: takuya.sogawa@aikernel.net
license: CC-BY-4.0
lang: en
created: 2026-05-25
last_updated: 2026-05-25
doi: 10.5281/zenodo.20373240
canonical_language: en
companion_languages:
  - ja
resource_type: publication
publication_type: technical-note
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

# IUniformPhaseProvider Specification

## A Minimal Contract for Independent Prime-Phase Generators

**Author:** Takuya Sogawa  
**ORCID:** 0009-0009-7499-2595  
**Version:** v0.1.0  
**DOI:** 10.5281/zenodo.20373240  
**Canonical language:** English  
**Companion language:** Japanese

---

## 1. Abstract

This technical note defines `IUniformPhaseProvider`, a minimal contract specification for isolating the provider-side phase source used in Riemann-Hypothesis-oriented prime-wave experiments. The specification is written in the vocabulary of Interface-Led Architecture (ILA): prime logarithmic frequencies are treated as a Provider, phase observation and integration are delegated to downstream Observers and Operators, and all stronger analytic number-theoretic assumptions are excluded from the Provider contract.

The central purpose of the interface is dependency isolation. Instead of mixing prime phases with analytic continuation, explicit formulae, zero correlations, or RH-equivalent error estimates, this specification extracts the weakest provider-side invariant: finite collections of logarithmic prime frequencies must be rationally independent and must induce equidistribution on a finite torus. From this contract, a fixed-scale mean-square cancellation bound can be formulated for the weighted finite signal on the critical line.

This document does not claim to prove the Riemann Hypothesis. It defines a formalizable input contract for later conditional proof experiments, Lean formalization, and numerical simulation. Its contribution is to separate the Provider responsibility from Observer and Operator responsibilities, thereby reducing circularity risk in future proof architectures.

---

## 2. Purpose and Position

This specification is intended as a supporting technical note for the paper *Prime-Wave Phase Transition and Conditional Proof Interfaces: A Second Interface-Led Approach to the Riemann Hypothesis*. That paper introduced `IUniformPhaseProvider` as a first separable contract for the prime-phase source. The present document expands that idea into a standalone contract specification suitable for implementation, formalization, and simulation.

In the ILA interpretation, the proof architecture is decomposed as follows.

| ILA role | RH-oriented interpretation | Responsibility |
|---|---|---|
| Provider | prime logarithmic phase source | supply independent phase modes |
| Observer | explicit formula, Chebyshev functions, zero-spectrum checks | observe macroscopic constraints |
| Operator | Perron transforms, Abel/Mellin regularization, contour shifts | transform provider signals into analytic interfaces |
| Contract | independence, equidistribution, cancellation, non-circularity | define what must be guaranteed |
| Fail-Closed | circular estimate, missing uniformity, invalid exchange | stop the proof claim |

The present specification concerns only the Provider side. It is deliberately smaller than a proof of RH.

---

## 3. Non-Proof Boundary

**Note.** The arguments and contracts in this specification do not prove the Riemann Hypothesis. They define a minimal provider-side interface that later proof attempts may inject as a precondition.

The specification does not assume:

- analytic continuation of $\zeta(s)$,
- Riemann's explicit formula,
- zero correlation statistics,
- Montgomery pair correlation,
- RH-equivalent error estimates such as $O(x^{1/2+\varepsilon})$,
- a Hilbert-Polya operator,
- or the exclusion of zeros off the critical line.

The interface asks only what a phase-source Provider must supply before downstream Operators may attempt to connect it to analytic number theory.

---

## 4. Interface Definition

### 4.1 Interface Name

```text
IUniformPhaseProvider
```

### 4.2 Input Parameters

For a finite scale $N$, the Provider exposes:

- $N \in \mathbb{N}$: the number of finite modes;
- $t \in \mathbb{R}$: the continuous phase parameter, corresponding to the imaginary part of the complex variable $s$;
- $\omega_n$: the $n$-th frequency, instantiated for the prime case as $\omega_n=\log p_n$;
- $p_n$: the $n$-th prime when the Provider is instantiated by actual primes.

The interface is not required to expose the analytic behavior of $\zeta(s)$.

### 4.3 Output Phase Signal

For each mode, the Provider returns the phase

$$
\theta_n(t) = -t\omega_n \pmod{2\pi}.
$$

For the prime instance,

$$
\omega_n = \log p_n,
\qquad
\theta_n(t)=-t\log p_n \pmod{2\pi}.
$$

The Provider returns phases, not zeros, error terms, or analytic continuations.

---

## 5. Contract Requirements

`IUniformPhaseProvider` must satisfy the following contracts.

### 5.1 Contract 1: Q-Linear Independence

For each finite $N$, the frequency vector

$$
\omega=(\omega_1,\dots,\omega_N)
$$

must be linearly independent over $\mathbb{Q}$:

$$
\sum_{n=1}^{N} q_n\omega_n=0,
\quad q_n\in\mathbb{Q}
\quad\Longrightarrow\quad
q_1=\cdots=q_N=0.
$$

For the prime instance $\omega_n=\log p_n$, this follows from unique factorization. Indeed, after clearing denominators, a relation

$$
\sum_{n=1}^{N} m_n\log p_n=0,
\quad m_n\in\mathbb{Z}
$$

would imply

$$
\prod_{n=1}^{N}p_n^{m_n}=1.
$$

By unique factorization, all $m_n$ must be zero.

### 5.2 Contract 2: Equidistribution on the Finite Torus

For fixed $N$, the phase flow

$$
t \mapsto (\theta_1(t),\dots,\theta_N(t))
$$

must be equidistributed on the finite torus $\mathbb{T}^N$ with respect to Haar measure.

Equivalently, for every continuous function $g:\mathbb{T}^N\to\mathbb{R}$,

$$
\lim_{T\to\infty}
\frac{1}{T}
\int_0^T
    g(\theta_1(t),\dots,\theta_N(t))\,dt
=
\int_{\mathbb{T}^N}g(x)\,d\mu_{\mathrm{Haar}}(x).
$$

This is the continuous-flow form of the Kronecker-Weyl equidistribution principle. The contract is stated for fixed finite $N$. Uniform-in-$N$ effective discrepancy estimates are not included in the minimal Provider contract and remain a later proof obligation.

### 5.3 Contract 3: Fixed-Scale Mean-Square Cancellation

Let

$$
S_N(t)
=
\sum_{n=1}^{N}p_n^{-1/2}e^{i\theta_n(t)}.
$$

Under Contract 1 and Contract 2, the time-averaged cross terms vanish for fixed $N$, yielding the expected mean-square energy

$$
\lim_{T\to\infty}
\frac{1}{T}
\int_0^T |S_N(t)|^2\,dt
=
\sum_{n=1}^{N}\frac{1}{p_n}.
$$

For actual prime weights, this is compatible with the standard harmonic-prime growth bound

$$
\sum_{n=1}^{N}\frac{1}{p_n}
=O(\log\log p_N).
$$

Thus the Provider-side cancellation contract may be recorded as

$$
\limsup_{T\to\infty}
\frac{1}{T}
\int_0^T
\left|
\sum_{n=1}^{N}p_n^{-1/2}e^{i\theta_n(t)}
\right|^2dt
\le C\log\log p_N
$$

for some constant $C$ and sufficiently large $N$.

This contract is weak by design. It is not a zero-exclusion theorem and does not imply RH. It only isolates a provider-side cancellation behavior at fixed finite scale.

---

## 6. Dependency Isolation

The Provider contract is intentionally isolated from stronger analytic assumptions. It does not depend on:

1. analytic continuation of $\zeta(s)$;
2. Riemann's explicit formula;
3. zero correlations or random matrix statistics;
4. prime-counting error terms equivalent or near-equivalent to RH;
5. operator-theoretic constructions such as a Hilbert-Polya Hamiltonian.

This isolation is the main architectural value of the specification. It allows the proof architecture to ask:

> What can be derived from the prime phase source alone, before importing analytic continuation, explicit formulae, or zero-spectrum assumptions?

In ILA terms, the Provider must not smuggle Observer or Operator responsibilities into its contract.

---

## 7. Mock Providers and Injection Strategy

Because the contract is stated in terms of rational independence and torus equidistribution, it can be tested with mock frequency vectors that are not prime logarithms.

A mock provider may use, for example, a finite vector such as

$$
\omega=(\sqrt{2},\sqrt{3},\sqrt{5})
$$

or any finite family for which rational independence can be established.

However, a mock provider must also specify its coefficient weights. Equidistribution of phases alone does not determine a prime-harmonic energy bound. The prime-specific bound in Contract 3 depends on the weights $p_n^{-1/2}$ and the growth behavior of the prime harmonic sum. For non-prime mocks, the corresponding mean-square energy is

$$
\sum_{n=1}^{N}|a_n|^2
$$

for the chosen coefficients $a_n$.

Mock injection is useful for:

- testing phase-cloud geometry;
- verifying the separation between Provider and Operator assumptions;
- simulating prime-wave phase transition analogues;
- formalizing conditional lemmas in Lean without importing zeta-zero assumptions.

---

## 8. Use Cases

### 8.1 Lean Conditional Proof Experiments

In Lean, the Provider may be represented as a typeclass assumption. Theorems can then be stated relative to a provider instance:

```lean
import Mathlib

class UniformPhaseProvider (N : Nat) where
  freqs : Fin N -> Real
  linearIndependent : LinearIndependent Rat freqs
  -- equidistribution and cancellation bounds should be added
  -- incrementally as definitions or theorem assumptions.
```

This makes the dependency boundary explicit. A theorem that requires only `UniformPhaseProvider N` cannot silently rely on RH-equivalent error bounds unless those bounds are explicitly added as assumptions.

### 8.2 C# Prime-Wave Simulation

In C# or another simulation environment, `IUniformPhaseProvider` can be implemented as a component that supplies phase vectors for fixed $N$ and $t$. Downstream simulation code can then visualize the induced complex walk, measure empirical phase distribution, and test finite-scale energy behavior.

The simulation should remain explicit about which part is provider-level and which part is operator-level. Phase generation belongs to the Provider. Fourier/Mellin/Perron transformations belong to Operators. Statistical or spectral diagnostics belong to Observers.

### 8.3 Explicit-Formula Bridge Precondition

The Provider contract is not the explicit formula. It is a precondition for later bridge construction. Once a provider supplies independent and equidistributed phases, an Operator may attempt to connect weighted prime signals to Chebyshev functions, von Mangoldt sums, Perron integrals, and zero-spectrum constraints.

If that bridge requires a stronger estimate, the stronger estimate must be declared as a new Contract rather than hidden inside the Provider.

---

## 9. Fail-Closed Behavior

The architecture is fail-closed.

If rational independence is not established, the Provider contract fails.

If equidistribution is unavailable or only assumed informally, the Provider contract remains incomplete.

If a proof step imports analytic continuation, explicit formulae, zero correlations, or RH-equivalent error estimates while claiming to use only the Provider contract, the proof interface fails.

In Lean, this principle becomes a type-level discipline: a theorem cannot use an assumption that has not been included in the theorem statement or imported context. In ordinary mathematical writing, the same discipline must be enforced by explicitly listing every analytic assumption.

---

## 10. Lean Formalization Notes

The intended Lean formalization should be staged.

First, define the frequency provider and rational independence.

```lean
import Mathlib

class UniformPhaseProvider (N : Nat) where
  freqs : Fin N -> Real
  linearIndependent : LinearIndependent Rat freqs
```

Second, define a phase map into the finite torus. The precise torus representation may use quotient groups, circle-valued maps, or a suitable existing structure in mathlib.

Third, add equidistribution as either a theorem derived from a Kronecker-Weyl formalization or as an explicit hypothesis while the theorem is being developed.

Fourth, prove the fixed-scale mean-square identity by expanding the square and using the vanishing of non-trivial time averages.

The cancellation bound should be separated into two layers:

1. a pure equidistribution identity,
2. a number-theoretic estimate for $\sum_{p\le x}1/p$.

This separation prevents a proof from confusing phase uniformity with prime harmonic growth.

---

## 11. Relationship to the Prime-Wave Paper

This specification corresponds to Section 4.1 of *Prime-Wave Phase Transition and Conditional Proof Interfaces: A Second Interface-Led Approach to the Riemann Hypothesis*.

The paper introduced `IUniformPhaseProvider` as the first separable contract in the proof architecture. This document expands that section into a standalone specification. Its role is to make the provider-side assumptions explicit enough to support future Lean formalization and numerical experiments.

The relationship is:

| Prime-Wave paper | This specification |
|---|---|
| introduces the provider contract | defines it as a standalone interface |
| treats phase uniformity as a proof boundary | states contract requirements explicitly |
| uses ILA to decompose proof obligations | provides a formal contract for one obligation |
| identifies mock-provider experiments | defines injection strategy and limitations |

---

## 12. Limitations and Non-Claims

This specification does not prove RH.

It also does not prove that the prime-wave phase-transition model can be connected to zero-exclusion. That connection requires the explicit-formula bridge, non-circular error estimates, and uniform control over limiting processes.

The contract is finite-scale. It assumes fixed $N$ before taking $T\to\infty$. Uniform estimates in both $N$ and $T$ are not included and should be treated as future proof obligations.

The mock-provider model is useful for testing architecture, but a mock provider does not reproduce arithmetic prime behavior unless its weights and growth laws are specified.

Finally, the Lean sketch is not a completed formalization. It is a minimal interface outline showing where assumptions should be placed.

---

## 13. Conclusion

`IUniformPhaseProvider` isolates the weakest provider-side phase contract needed by the prime-wave RH research program. By separating rational independence, torus equidistribution, and fixed-scale mean-square cancellation from analytic continuation, explicit formulae, zero correlations, and RH-equivalent error estimates, the specification creates a clean boundary for future conditional proofs and simulations.

The value of the interface is not that it proves the Riemann Hypothesis. Its value is that it prevents proof attempts from silently mixing Provider, Observer, and Operator responsibilities. It thereby gives the prime-wave proof architecture a minimal, testable, and fail-closed starting point.

---

## References

1. Weyl, Hermann. "Über die Gleichverteilung von Zahlen mod. Eins." *Mathematische Annalen*, vol. 77, 1916, pp. 313-352. DOI: 10.1007/BF01475864.
2. Titchmarsh, E. C. *The Theory of the Riemann Zeta-Function*. 2nd ed., revised by D. R. Heath-Brown, Oxford University Press, 1986.
3. Davenport, Harold. *Multiplicative Number Theory*. 3rd ed., revised by Hugh L. Montgomery, Springer, 2000.
4. The mathlib Community. "The Lean Mathematical Library." *Proceedings of the 9th ACM SIGPLAN International Conference on Certified Programs and Proofs*, 2020. DOI: 10.1145/3372885.3373824.
5. Sogawa, Takuya. "Interface-Led Architecture (ILA): A Software Development Methodology for the AI Era, Validated by the AIKernel Execution Model." Zenodo, 2026. DOI: 10.5281/zenodo.20290614.
6. Sogawa, Takuya. "Provider-Observer-Operator: A Role-Based Abstraction Discipline for Interface-Led Architecture." Zenodo, 2026. DOI: 10.5281/zenodo.20322690.
7. Sogawa, Takuya. "Prime-Wave Phase Transition and Conditional Proof Interfaces: A Second Interface-Led Approach to the Riemann Hypothesis." Zenodo, 2026. DOI: 10.5281/zenodo.20357202.
