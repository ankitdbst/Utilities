#! /bin/bash
# Run under 4th year final
if [ -z "$1" ]; then
  echo usage: $0 Name Roll
  exit
fi
if [ -z "$2" ]; then
  echo usage: $0 Name Roll
  exit
fi
# Make new folder
mkdir "$1"
find . -name '*.cpp' -print0 | xargs -0 -I {} cp {} "$1"
echo "Finished copying to $1"
# Change fileheader
find "$1" -name '*.cpp' -exec sed -i "s/Animesh Anand/$1/g" {} \;
find "$1" -name '*.cpp' -exec sed -i "s/07011208/$2/g" {} \;
echo "Renamed fileheader"
# Remove deprecated functions
find "$1" -name '*.cpp' -exec sed -i "s/#include<conio.h>//g" {} \;
find "$1" -name '*.cpp' -exec sed -i "s/getch();//g" {} \;
echo "Removed deprecated functions"
