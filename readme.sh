#!/bin/bash

pwd=$PWD
readme=$pwd/README.md
excluded_algo=("x64" "Debug" "Release")
pattern="^[[:digit:]]+-[[:print:]]+.cpp$"

echo -e "# Problem-Solving\n" > "$readme"

for judge in ./*/
do
  echo -e "### $(basename "$judge")\n" >> "$readme"
  cd "$judge"

  for algo in ./*/
  do
    if ! [[ ${excluded_algo[@]} =~ $(basename "$algo") ]]
    then
      echo -e "##### $(basename "$algo")\n" >> "$readme"
      cd "$algo"

      for problem in ./*
      do
        if [[ $(basename "$problem") =~ $pattern ]]
        then
          problem_name=$(basename "$problem")
          echo -e "- ${problem_name%.*}" >> "$readme"
        fi
      done

      echo "" >> "$readme"
      cd ..
    fi
  done

  cd ..
done

cd "$pwd"
