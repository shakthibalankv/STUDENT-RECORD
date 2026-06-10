outfile:main.o add.o show.o save.o load.o delete.o exit.o delall.o modify.o sort.o reverse.o
	cc main.c add.c show.c save.c load.c delete.c exit.c delall.c modify.c sort.c reverse.c -o outfile	

main.o:main.c
	cc -c main.c
add.o:add.c
	cc -c add.c
show.o:show.c
	cc -c show.c
save.o:save.c
	cc -c save.c
load.o:load.c
	cc -c load.c
delete.o:delete.c
	cc -c delete.c
exit.o:exit.c
	cc -c exit.c
delall.o:delall.c
	cc -c delall.c
modify.o:modify.c
	cc -c modify.c
sort.o:sort.c
	cc -c sort.c
reverse.o:reverse.c
	cc -c reverse.c
