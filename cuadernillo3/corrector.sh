carpetaConPruebas="prueba"
dirTads="pruebas/$carpetaConPruebas/"
dirMain="codigo/src/tad.cpp"
extension=".cpp"

cd $dirTads
numPruebas=$(find . -maxdepth 1 -type f | wc -l)
echo $numPruebas
cd ..
cd ..
echo $(pwd)

#limite=$numPruebas / 2
#echo $limite
for i in $(seq 1 $1); do

  echo "============================================================="

  tad="tad$i"
  if [ $i -le 9 ]
  then
    tad="tad0$i"
  fi

  echo $tad

  >  codigo/src/tad.cpp
  cp "$dirTads$tad$extension" "$dirMain"

  salida="$tad.out"
  cd codigo
  make -s > $salida
  cd ..

  diff "codigo/$salida" "$dirTads/$tad$extension.sal"

  echo "=============================================================\n"

done
