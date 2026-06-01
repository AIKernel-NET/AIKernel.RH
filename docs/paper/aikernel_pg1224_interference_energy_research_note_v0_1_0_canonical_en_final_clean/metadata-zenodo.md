# Zenodo Metadata Draft

## Basic Information

- Resource type: Publication
- Publication type: Technical note
- Title: Phase-Interference Energy and the Formal Structure of the PG1224 Prime Generation System
- Subtitle: A Lean 4 Formalization of Prime = Energy 0 = Stable Fixed Point
- Version: v0.1.0
- Publication date: 2026-06-01
- DOI: 10.5281/zenodo.20483437
- Creator: Sogawa, Takuya
- ORCID: https://orcid.org/0009-0009-7499-2595
- Affiliation: AIKernel Project
- License: Creative Commons Attribution 4.0 International (CC BY 4.0)
- Language: English
- Additional language: Japanese
- Canonical manuscript: paper-en.pdf / paper-en.md
- Companion translation: paper-ja.pdf / paper-ja.md

## Description

This research note reformulates the elementary number-theoretic structure of natural numbers using the operational concept of phase-interference energy. In this model, a prime number is treated as a stable fixed point that contains no non-trivial internal interference.

The note defines interference energy as a measure of the non-trivial divisors of a natural number, clarifies the boundary condition excluding 0 and 1 through the domain condition `2 ≤ n`, and sketches a Lean 4 formalization of the equivalence among `Nat.Prime n`, `interferenceEnergy n = 0`, and `isStableFixedPoint n`.

It also introduces PG1224, a prime-candidate generation system based on residue-class filtering modulo 12 and 24. The filter is interpreted as cancellation of trivial interference caused by divisibility by 2 and 3. The note does not claim a new definition of primality or computational superiority over existing sieve methods; rather, it reconstructs the standard notion of primality in the vocabulary of energy minimization, stable fixed points, formal verification, and AIKernel-style governance models.

The English manuscript is the canonical version. The Japanese manuscript is included as a companion translation.

## Keywords

AIKernel; PG1224; Interference Energy; Prime Numbers; Lean 4; Formal Verification; Residue-class Filtering; Stable Fixed Point; Governance Model

## Files

- paper-en.pdf (Preview / canonical)
- paper-ja.pdf (Companion translation)
- paper-en.md
- paper-ja.md
- metadata-zenodo.md
- review-notes.md
- CITATION.cff
- .zenodo.json
- CHECKSUMS.txt

## Archive Name

- aikernel_pg1224_interference_energy_research_note_v0_1_0_canonical_en_final_clean.zip

## References

- The mathlib Community. (2020). The Lean mathematical library. Proceedings of the 9th ACM SIGPLAN International Conference on Certified Programs and Proofs, 367-381. https://doi.org/10.1145/3372885.3373824
- de Moura, L., Kong, S., Avigad, J., van Doorn, F., & von Raumer, J. (2015). The Lean Theorem Prover. Automated Deduction - CADE-25, Lecture Notes in Computer Science, 9195, 378-388. Springer. https://doi.org/10.1007/978-3-319-21401-6_26
- Lean FRO. (2026). Lean 4 Manual. Lean Focused Research Organization.
- Sogawa, T. (2026). AIKernel Trajectory Governance Model: A Kernel-Level Framework for Convergent Decision Control over Stochastic Language Model Inference. Zenodo.
- Sogawa, T. (2026). AIKernel Formal Foundations: Contract-Based Semantic Execution for Governed AI Systems. Zenodo.

## Packaging Notes

- Added an English canonical manuscript.
- Retained the Japanese manuscript as a companion translation.
- Updated Zenodo metadata, citation metadata, and `.zenodo.json` to treat English as canonical.
- Regenerated both PDFs and checksums.
- Packaged only final public files.
- Renamed the public archive to include `canonical_en` in order to avoid stale-download/cache confusion from the previous ZIP filename.
