# Sim/Reco: w/LBL + Near Detector

## Pandora

Pandora provides a multi-algorithm approach to LAr TPC pattern recognition

2 algorithm passes, neutrino and cosmic ray

**2 pass reconstruction was developed for microBoone**

- The drift volumes are reconstructed and then stitched.
- Then, the cosmic ray is taken out
- neutrino reco is run

**cosmic score:** high number up to one means more likely to be cosmic and low number means it is less likely to be cosmic

cutoff was set to .6 for microBoone but protoDune will probably be lower, .5 or .4

Pattern recognition by pandora is very strict, it will mark things as incorrect that are almost close, it does this since it is hard to correct mistakes later.

Usually you get one pf particle associated with a muon and one with a proton.

Shower from second photon is missing 41% of the cases

Handling multiple drift volumes as a single instance is a big step forward for Pandora

## Shower Performance reconstruction studies
