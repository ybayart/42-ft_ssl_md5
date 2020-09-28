#! /bin/bash

make ffclean>/dev/null
make -j>/dev/null

for algo in md5 sha1 sha224 sha256 sha384 sha512 sha512-224 sha512-256 sha3-256 sha3-384 sha3-512 whirlpool
do
	echo -n $algo...
	state=0
	for file in libft/*
	do
		if [ "$(./ft_ssl $algo -q $file)" != "$(openssl $algo -r $file|awk -F ' ' '{print $1}')" ]
		then
			if [ $state = 0 ]
			then
				state=1
				echo -ne '\r' KO $algo
			fi
			echo -ne '\n  ->' $file
		fi
	done
	if [ $state = 0 ]
	then
		echo -ne '\r' ok $algo
	fi
	echo 
done

make ffclean>/dev/null
