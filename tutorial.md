## Dune Tutorial Notes:

Sourcing `setup_dune.sh` sets up `ups`, `git`, `git flow`, `mrb` and defines MRB_PROJEECT env variable. Build system is being changed in June.

`Setup dunetpc v06_34_00 -q e14:prof`

Larsoft release is consistent set of Larsoft products

dune_pardata a ups product for large DUNE-specific config files

 Integration   |               production release
:------------: | :--------------------------------------------:
created weekly | Created when a experiment says it's production

### UPS

ups is a tool allowing multiple concurrent versions of products to exist on a single machine

`setup` selects single instance to use by defining a set of environmental variables

`ups list -aK+ <product name="">` list of all product names

#### Qualifiers

2 qualifiers, letter number combo either `"prof"` or `"debug"` : separates qualifiers doesn't matter which order it goes in

letter number combo specifies compiler version + compiler options currently at `e14`

lar is alias to art

Larsoft is built on top of art

Modules are configurable and dynamically loaded Services, Configurable global utilities

run time config of art, modules, services and tools specified in FHiCL

Art workbook is good resource

If same name tables are created in table, the table will get silently overwritten, so the order in which things are parsed is important

Geometry details are specified in `GDML` file. It's readable by Geant4 for sim and Root for Reco.

Structured builders and sub builders to create gdml files.

`FFICL_FILE_PATH` environment variable specifies where art finds the fcl file

### FHiCL file best practices:

Presentation 2016 LArSoft Workshop

Basically calls for highly nested structures that layer override

`fhicl-expand` Performs all `\#include` directives and creates single output with the result

`fhicl-dump` Parses the hierarch **prints final state** all parameters `--annotate` option also lists fcl file + line number

No centralized tools for finding FHiCL files

- follow FHICL_FILE_PATH `echo $FHICL_FILE_PATH | sed`

### Processing Chain:

**Event generation->Geant4 simulation->Detector simulation->Reconstruction**

GENIE is an event generation module

Neutrino event generator `larsim/larsim/EventGenerator/GENIE`

### Gallery

Gallery allows the reading of event data from art/ROOT data files outside of the art event-processing framework executable

gallery provides access to only the event data. No facilities of framework.

Gallery can be used to write

- Compiled C++ programs
- ROOT macros
- Using PyROOT, python scripts

Gallery to use python or interactive ROOT access art/ROOT files

When not to use Gallery:

- need framework abilities
- when you want to put stuff into an event
