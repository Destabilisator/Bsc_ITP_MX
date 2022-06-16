#!/bin/bash

# args: low or high
if [[ "$#" -ge 1 ]]; then
	regime=$1
else
	regime=low
fi

# data
start=0.0
end=2.5
h=0.0

#plot
plotstart=25
plotend=$end

noX=-X
#noX=noX

start_time=$SECONDS
#build=build
build=cmake-build-release

if [[ "$OSTYPE" == "msys" ]]; then
	prgm=Bsc_ITP_MP.exe
	pth=python
else
	prgm=Bsc_ITP_MP
	pth=python3
fi

if [[ "$regime" == "low" ]]; then
	echo "low regime" && echo ""
    # $pth plotting/deleteData.py 6 SG
	# ./$build/$prgm 6 $start $end 50 $h -1 $noX silent && echo "" # 10000
    # $pth plotting/deleteData.py 8 SG
	# ./$build/$prgm 8 $start $end 50 $h -1 $noX silent && echo "" # 10000
    # $pth plotting/deleteData.py 10 SG
	# ./$build/$prgm 10 $start $end 50 $h -1 $noX silent && echo "" # 5000
    # $pth plotting/deleteData.py 12 SG
	# ./$build/$prgm 12 $start $end 50 $h -1 $noX silent && echo "" # 1000
	# $pth plotting/deleteData.py 14 SG
	# ./$build/$prgm 14 $start $end 50 $h -1 $noX silent && echo "" # 50
	# $pth plotting/deleteData.py 16 SG
	# ./$build/$prgm 16 $start $end 50 $h 1 $noX silent && echo ""
	# $pth plotting/deleteData.py 18 SG
	# ./$build/$prgm 18 $start $end 25 $h 1 $noX silent && echo ""
	$pth plotting/plotSpinGapQT.py $regime && echo "" && echo ""
elif [[ "$regime" == "high" ]]; then
	echo "high regime" && echo ""
	$pth plotting/deleteData.py 20 SG
	./$build/$prgm 20 $start $end 25 $h -1 $noX silent && echo ""
	$pth plotting/deleteData.py 22 SG
	./$build/$prgm 22 $start $end 25 $h -1 $noX silent && echo ""
	$pth plotting/deleteData.py 24 SG
	./$build/$prgm 24 $start $end 20 $h -1 $noX silent && echo ""
	$pth plotting/deleteData.py 26 SG
	./$build/$prgm 26 $start $end 20 $h -1 $noX silent && echo ""
	$pth plotting/deleteData.py 28 SG
	./$build/$prgm 28 $start $end 20 $h -1 $noX silent && echo ""
	$pth plotting/deleteData.py 30 SG
	./$build/$prgm 30 $start $end 20 $h -1 $noX silent && echo ""
	$pth plotting/deleteData.py 32 SG
	./$build/$prgm 32 $start $end 20 $h -1 $noX silent && echo ""
	$pth plotting/plotSpinGapQT.py $regime && echo "" && echo ""
else
	echo "nope" && exit
fi

# start_time_plots=$SECONDS

elapsed=$(( SECONDS - start_time ))
#echo "plotting done, this took: $elapsed_plots seconds"
echo "all done, total elapsed time: $elapsed seconds"
