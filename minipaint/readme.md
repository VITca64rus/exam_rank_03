my program - main.c
program from ecole42 - our_mini_paint.c

for test and check results:
gcc main.c && ./a.out maps/2 > res
gcc our_mini_paint.c && ./a.out maps/2 > res
diff -s res res1

If program work correctle you can see: "Files res and res1 are identical"