cp $1 ./src/gdfGenerator/
cp $2 ./src/gdfGenerator/
cd ./src/gdfGenerator
bash xtoGDF.sh $1 $2
cp ./dist.gdf ./src/QueryParser
cd ../QueryParser
bash init
make
