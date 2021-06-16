#!/usr/bin/bash
#=========================================================================
#Name        : read_registry.sh
#Description : Script makes use of the regtool of cygwin
#Where to run: in Cygwin terminal 
#========================================================================

reg_helper () {
	input="/HKLM/SOFTWARE/Microsoft/Windows\ NT/$1"
	output=`regtool get $input`
	echo $output
}

product_name=$(reg_helper "ProductName";)
echo "Windows Product Name: $product_name"

