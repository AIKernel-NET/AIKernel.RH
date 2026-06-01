# Review Notes

## Document

- Title: Phase-Interference Energy and the Formal Structure of the PG1224 Prime Generation System
- Japanese title: 位相干渉エネルギーと PG1224 素数生成系の形式的構造
- Version: v0.1.0
- DOI: 10.5281/zenodo.20483437
- Author: Takuya Sogawa
- ORCID: https://orcid.org/0009-0009-7499-2595
- Date: 2026-06-01

## Canonicality

- `paper-en.md` and `paper-en.pdf` are the canonical manuscripts.
- `paper-ja.md` and `paper-ja.pdf` are included as a companion Japanese translation.

## Applied Review Changes

### 1. English canonical manuscript

Created a natural English version of the research note and made it the canonical manuscript for Zenodo publication.

### 2. Completeness proof sketch

Retained and translated the expanded `prime_implies_candidate_PG1224` proof sketch:

1. Handle the special cases `n = 2` and `n = 3`.
2. For `n > 3`, primality implies that `n` is divisible by neither `2` nor `3`.
3. Therefore `n` is coprime to `6`.
4. Hence `n` falls into the residue classes represented by the PG1224 filters modulo `12` and `24`.

### 3. interferenceEnergy example

Retained and translated the concrete calculation example:

```text
12 -> {2, 3, 4, 6} -> energy = 4
13 -> {}            -> energy = 0
```

### 4. PG1224 naming note

Retained and translated the footnote explaining that `PG1224` refers to a Prime Generator based on residue-class filtering modulo `12` and `24`.

## Packaging

- Generated `paper-en.md` as the canonical Markdown manuscript.
- Generated `paper-en.pdf` from the canonical Markdown manuscript.
- Regenerated `paper-ja.pdf` from the updated companion translation.
- Updated Zenodo metadata draft, citation metadata, and `.zenodo.json`.
- Regenerated `CHECKSUMS.txt` after final file creation.
- Packaged only final publication files into `aikernel_pg1224_interference_energy_research_note_v0_1_0_final_clean.zip`.


## Final Archive Rename

- Renamed the distribution archive to `aikernel_pg1224_interference_energy_research_note_v0_1_0_canonical_en_final_clean.zip`.
- Purpose: avoid browser/platform cache collisions caused by reusing the previous `final_clean.zip` filename.
- Internal contents remain the English-canonical Zenodo package.
