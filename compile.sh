
g++ fgt_fixer.cxx -g -L${LOG4CPP_LIB} -llog4cpp `root-config --cflags --glibs` `genie-config  --libs` -I`genie-config --topsrcdir`  -I${DUNENDTF_INC} -lXMLIO  -lEGPythia6 -lGeom    -lxml2  -o fgt_fixer

