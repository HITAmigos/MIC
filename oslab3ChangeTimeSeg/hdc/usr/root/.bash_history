ll
cd 
cd /etc
laceup -w 1 /dev/hd0
cd 
dd if=/dev/hd0 of=MBR3 bs=512 count=1
ll
mcopy MBR3 b:
mcopy part13 b:
sync
sync
exit
cd /etc
ls
bootlace
ls
ll
chmod 711 bootlace 
ls
ll
./bootlace
objdump bootlace
objdump bootlace -r
od
od
cd /usr/bin
ls
cd /etc
hexdump bootlace
hexdump bootlace | more
hexdump laceup | more
hexdump bootlace | more
ls
pwd
cd
ls
cd shoe
ls
cat Readme 
cat readme | more
ls
cat config | more
exit
cd /etc
ls
laceup -w /dev/hde0
laceup -w /dev/hd0
laceup -w 1 /dev/hd1 wini
/etc/laceup -w 1 /dev/hd1 wini
/etc/laceup  /dev/hd0 wini
/etc/laceup -w 1 /dev/hd1 wini
/etc/laceup -w 1 /dev/hd1
/etc/laceup -w 1 /dev/hd0
/etc/laceup /dev/hd1 wini
/etc/laceup -w 1 /dev/hd0
pwd
ls
ll
ll /
cd
ls
dd if=MBR3 of=/dev/hd0 bs=512 count=1
dd if=part13 of=/dev/hd1 bs=512 count=1
cd /etc
ls
laceup -w 1 /dev/hd0
laceup /dev/hd1 wini
sync
sync
ls
ll
chmod 755 bootlace 
ls
ll
chmod 755 winiboot
ll
chmod 644 config
chmod 644 disktab
ls
ll
laceup -w 1 /dev/hd0
laceup /dev/hd1 wini
exit
mdir b:
mcopy b:mbr3 mbr3
ls
hexdump mbr3
dd if=mbr3 of=/dev/hd0 bs=512 count=1
sync
sync
exit
ls
ll
dd if=MBR3 of=/dev/hd0 bs=512 count=1
sync
sync
sync
exit
dir
dd if=/dev/hd1 of=part14 bs=512 count=2
ll
hexdump -x part14 | more
hexdump part14 | more
hexdump part14 | more
cd /usr/src/linux
ls
ll
hexdump Image | more
chroot
rootdev
rdev
chod
od
vd
cd /bin
ls
cd /usr/bin
ls
cd /usr/src/linux
ls
vi Makefile 
ll
make clean
make
vi Makefile 
ll
rm Image
make
cd /etc
ls
vi config
cd ..
laceup /dev/hd1 wini
cp /usr/src/linux/Image .
ls
ll
exit
ls
ll
rm part*
ls
ll
rm MBR*
ls
ll
rm mbr3
ls
ll
rm image
ls
ll
cd ..
ls
ll
cd ..
ls
ll
cd /usr/src/linux
ls
vi Makefile 
ls
rm Image 
make 
cd /
ls
rm Image 
ls
cd /etc
ls
vi config
ls
laceup -w 1 /dev/hd0
laceup /dev/hd1 wini
exit
ls
cd /etc
ls
cat rc
ll
df
ls
fdisk
ls
df
l
ls
cd ..
ls
ll
cd
ls
ll
exit
exit
cd /usr/src/linux
ll
mdir b:
mcopy System.map b:
exit
cd /bin
dir
objdump 
objdump -h /bin/vi
cd
objdump -h /bin/vi
ll
what
wc
wcc
wgcc
wg
gcc -c -o hello.o hello.c
ll
gcc -c -o hello.o hello.c
gcc -o hello hello.o
objdump
objdump -h hello.o
objdump -h hello
objdump -h  /bin/sh 
objdump -hn  /bin/sh 
objdump -hrs  /bin/sh 

objdump -hr  /bin/sh 
ll /bin/sh
objdump -hrnt  /bin/sh 

objdump -hrnt  /bin/vi
objdump -hrnt  /bin/vi | more
objdump -hrnt  /bin/vi | more
exit
ls
ll
cd /dev
ll
exit
exit
ll
cd ..
ll
ll -la
cd /
ls
ll
cd /etc
ll
cd ..
ll
cd
ll
exit
dir
ls
ll
ll
cd /
ls
ll
cd shoelace
ls
ll
cd /usr/src/linux
ls
ll
make clean; make
ll
lsl
ls
sync
sync
exit
ls
cd /etc
ls
ll
cd cat profile 
vi profile
ls
ll
cd ..
ls
ls
ll
cd /etc
ls
ll
cat rc
ls
ll
cd ..
ls
ll
cd image
ls
ll
cd ..
ls
ll
cd etc
ls
ll
cat config
vi config
exit
cd /usr/src/linux
ls
vi Makefile 
ls
make clean; make
ll
cd tools
ll
cd ..
ls
vi Makefile 
ll
cd fs
vi Makefile 
ll
cd ..
ls
ll
cd kernel/
ls
vi Makefile 
ll
cd blk_drv/
vi Makefile 
cd ../chr_drv/
vi Makefile 
cd ../math
vi Makefile 
ll
cd ..
ll
cd ..
ll
cd lib
ls
vi Makefile 
ll
cd ..
ll
cd mm
vi Makefile 
ll
cd ..
ls
make clean ;make
ll
cd tools
ll
cd ..
ls
ll
cd ..
ls
ll
tar zcvf linux.tgz linux
ll
mdir b:
mdel b:bc.tar
ls
ll
mdir b:
mdel b:*.s
mdir b:
mdel b:install.*
mdir b:
mdel b:su.*
mdir b:
ll
mcopy linux.tgz b:
ll
sync
exit
mdir b:
exit
cd /usr/src/linux
ls
ll
cd ..
ls
cp -a linux linux-gdb
cd linux-gdb/
ls
vi Makefile 
cd boot/
ls
vi bootsect.s
ls
cd ..
cd tools
vi build.c
ls
cd ..
ls
make clean; make
ll
cd tools
ll
cd ..
ls
cd ..
ll
tar zcvf linux-gdb.tgz linux-gdb/
ll
mdir b:
mdel b:linux.tgz
mdir b:
ll
mcopy linux-gdb.tgz b:
mdir b:
sync
sync
sync
exit
dir
mdir b:
mcopy b:linux0.tgz .
ls
tar zxvf linux0.tgz
ls
ll
cd linux-0.00
ls
make
ls
make clean
dir
ll
cd ..
ls
ll
vi README 
ll
exit
ls
dir
ls
vi
cd /
ls -l
uname
whoami 
haha
cd /bin
ls
ps
ps aux
cd
ls
vi hello.c
ls
./hello
./shoe
cd shoe
ls
ls
vi Readme
ls
./shoelace 
ls -l
./laceup 
./shoelace 
cd src
ls
cd ..
cd ..
ls
clear
ls
cd /
ls
cd mnt
ls
ls
vi
ls
ls -l
cd image
ls
exit
exit
ls
exit
ls
exit
ls
df -h
df
exit
ls
exit
uanme
uname
exit
ls
ll
ll -a
exit
ls
mount
exit
