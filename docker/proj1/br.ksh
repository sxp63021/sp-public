#don't specify which ksh to run
## #!/usr/bin/ksh

#function name: show_usage
function show_usage {
  print "\nusage: $(basename ${first_arg}) ( config_file ) [ -v ] \n"
  print "  [ -v ] - verbose mode (log to current window)\n"
  print "Version: v1.0.0 base version"
  exit 1
}

#function cleanup
function cleanup {
  
  name='cleanup'
  print "cleanup ($1) called"
  trap - INT TERM EXIT #avoid reexecuting handlers

  #remove any lock files if created

  if [ "$1" = 130 ]; then
    print "program interrupted"
    #kill -INT $$
  elif [ "$1" = 143 ]; then
    print "program terminated"
    #kill -TERM $$
  else
    print "none of the reasons checking for"
  fi


}

#function set_environment
function set_environment {

  #get the day when running
  day=$(date '+%m%d%Y')

  basedir=$(dirname $(dirname ${first_arg}))
  echo "basedir: ${basedir}"

  echo "Number of args: ${#}"

  #only run the code if the arguments are passed or else skip it
  if [ ${#} -gt 0 ]
    then
      element=( "$@" )
      # echo "debug ${element[0]}"
      for i in ${element[@]}
      do
        echo $i
	if [[ $i = "-v" ]]
	then
	  print "Verbose mode selected"
	  verbose='yes'
	fi
      done

      #source the first argument
      #. ${element[0]}
      #check if file exists
      if [[ -e ${element[0]} ]]
      then
	 print "file ${element[0]} exists"
         source ./${element[0]}
      else
	 print "file ${element[0]} does not exist"
      fi
  fi

}

function move_files {
# Ensure the source directory exists
if [[ ! -d "$inputdir" ]]; then
    echo "Source directory '$inputdir' does not exist."
    exit 1
fi

# Ensure the destination directory exists
if [[ ! -d "$outputdir" ]]; then
    echo "Destination directory '$outputdir' does not exist."
    exit 1
fi

# Move files from dir1 to dir2
mv "$inputdir"/* "$outputdir/"

echo "Files moved from $inputdir to $outputdir."
}


#main program

first_arg=${0}

#exit if not args
if [ ${#} -eq 0 ]
  then
    show_usage
fi

# trap signals, so proper cleanup is done before exiting
trap 'cleanup 130' INT
trap 'cleanup 143' TERM

#initialize
#set any environment variables
set_environment ${*}

#check if the inputdir variables are set
if [[ -v inputdir ]]
then
  print "inputdir variable is set"
  print "inputdir: ${inputdir}"
else
  print "inputdir variable is not set"
fi

#check if the outputdir variables are set
if [[ -v outputdir ]]
then
  print "outputdir variable is set"
  print "outputdir: ${outputdir}"
else
  print "outputdir variable is not set"
fi

#move files in inputdir to outputdir
move_files

#while true
#do
#date
#sleep 10
#done

