classname=$1

echo "#include “./${classname}.hh”" > ${classname}.cc
echo "${classname}.hh::${classname}.hh()" >>  ${classname}.cc
echo "{}" >> ${classname}.cc
echo "${classname}.hh::~${classname}.hh()" >> ${classname}.cc
echo "{}" >> ${classname}.cc

echo "#ifndef ${classname}.hh_hh" > ${classname}.hh
echo "#define ${classname}.hh_hh" >> ${classname}.hh
echo "class ${classname}.hh" >> ${classname}.hh
echo "{" >> ${classname}.hh
echo "	public:" >> ${classname}.hh
echo "	${classname}.hh();" >> ${classname}.hh
echo "	~${classname}.hh();" >> ${classname}.hh
echo "	private:" >> ${classname}.hh
echo "};" >> ${classname}.hh
echo "#endif" >> ${classname}.hh
