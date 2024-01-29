
#ifndef EBPF_TEST_CODE_H_
#define EBPF_TEST_CODE_H_

const unsigned char test_1[] =
	"\x71\x12\x0c\x00\x00\x00\x00\x00\x71\x13\x0d\x00\x00\x00\x00\x00\x67\x03\x00\x00\x08\x00\x00\x00\x4f\x23\x00\x00\x00\x00\x00\x00\xb7\x00\x00\x00\x00\x00\x00\x00\x55\x03\x25\x00\x08\x00\x00\x00\x71\x12\x17\x00\x00\x00\x00\x00\x55\x02\x23\x00\x06\x00\x00\x00\x71\x12\x0e\x00\x00\x00\x00\x00\x07\x01\x00\x00\x0e\x00\x00\x00\x57\x02\x00\x00\x0f\x00\x00\x00\x67\x02\x00\x00\x02\x00\x00\x00\x0f\x21\x00\x00\x00\x00\x00\x00\xb7\x00\x00\x00\x00\x00\x00\x00\x69\x14\x0c\x00\x00\x00\x00\x00\x07\x01\x00\x00\x14\x00\x00\x00\x77\x04\x00\x00\x02\x00\x00\x00\x57\x04\x00\x00\x3c\x00\x00\x00\xbf\x42\x00\x00\x00\x00\x00\x00\x07\x02\x00\x00\xec\xff\xff\xff\xb7\x05\x00\x00\x15\x00\x00\x00\xb7\x03\x00\x00\x00\x00\x00\x00\x2d\x45\x14\x00\x00\x00\x00\x00\xbf\x35\x00\x00\x00\x00\x00\x00\x67\x05\x00\x00\x20\x00\x00\x00\xc7\x05\x00\x00\x20\x00\x00\x00\xbf\x14\x00\x00\x00\x00\x00\x00\x0f\x54\x00\x00\x00\x00\x00\x00\x71\x45\x00\x00\x00\x00\x00\x00\x15\x05\x04\x00\x01\x00\x00\x00\x15\x05\x0c\x00\x00\x00\x00\x00\xbf\x36\x00\x00\x00\x00\x00\x00\x15\x05\x09\x00\x05\x00\x00\x00\x05\x00\x02\x00\x00\x00\x00\x00\x07\x03\x00\x00\x01\x00\x00\x00\xbf\x36\x00\x00\x00\x00\x00\x00\x71\x43\x01\x00\x00\x00\x00\x00\x0f\x63\x00\x00\x00\x00\x00\x00\x67\x03\x00\x00\x20\x00\x00\x00\xc7\x03\x00\x00\x20\x00\x00\x00\x6d\x32\xee\xff\x00\x00\x00\x00\x05\x00\x01\x00\x00\x00\x00\x00\xb7\x00\x00\x00\x01\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00";

/*
ja +1
mov %r0, 1
exit
*/
const unsigned char jmp_to_exit[] = "\x05\x00\x01\x00\x00\x00\x00\x00"
				    "\xb7\x00\x00\x00\x01\x00\x00\x00"
				    "\x95\x00\x00\x00\x00\x00\x00\x00";

// original code from libebpf repo
const unsigned char bpf_add_mem_64_bit_minimal[] =
	""
	"\x61\x12\x00\x00\x00\x00\x00\x00"
	"\x61\x10\x04\x00\x00\x00\x00\x00"
	"\x0f\x20\x00\x00\x00\x00\x00\x00"
	"\x95\x00\x00\x00\x00\x00\x00\x00"
	"";

/// ebpf code generate by compile framework
// static int (*add)(int a, int b) = (void *)0x3;
// int print_and_add1(struct data *d, int sz) {
//  	return add(1, 3);
// }
const unsigned char bpf_function_call_add[] =
	""
	"\xb7\x01\x00\x00\x01\x00\x00\x00"
	"\xb7\x02\x00\x00\x03\x00\x00\x00"
	"\x85\x00\x00\x00\x03\x00\x00\x00"
	"\x95\x00\x00\x00\x00\x00\x00\x00";

// static void (*print_bpf)(char *str) = (void *)0x2;
// int print_and_add1(struct data *d, int sz) {
// 	char a[] = "hello";
// 	print_bpf(a);
//  	return 0;
// }
const unsigned char bpf_function_call_print[] =
	""
	"\xb7\x01\x00\x00\x6f\x00\x00\x00"
	"\x6b\x1a\xfc\xff\x00\x00\x00\x00"
	"\xb7\x01\x00\x00\x68\x65\x6c\x6c"
	"\x63\x1a\xf8\xff\x00\x00\x00\x00"
	"\xbf\xa1\x00\x00\x00\x00\x00\x00"
	"\x07\x01\x00\x00\xf8\xff\xff\xff"
	"\x85\x00\x00\x00\x02\x00\x00\x00"
	"\xb7\x00\x00\x00\x00\x00\x00\x00"
	"\x95\x00\x00\x00\x00\x00\x00\x00";

/*
int add_test(struct data *d, int sz) {
	return d->a + d->b;
}
in 64 bit:
*/
const unsigned char bpf_add_mem_64_bit[] = {
	0x7b, 0x1a, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0x63, 0x2a, 0xf4, 0xff,
	0x00, 0x00, 0x00, 0x00, 0x79, 0xa1, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x61, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x11, 0x04, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

/*
int mul_test() {
	int a = 1;
	int b = 2;
	int c = a * b;
	return c;
}
in 64 bit: using clang -target bpf -c mul.bpf.c -o mul.bpf.o to compile
*/
const unsigned char bpf_mul_64_bit[] = {
	0xb7, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x63, 0x1a, 0xfc, 0xff,
	0x00, 0x00, 0x00, 0x00, 0xb7, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
	0x63, 0x1a, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00, 0x61, 0xa1, 0xfc, 0xff,
	0x00, 0x00, 0x00, 0x00, 0x61, 0xa2, 0xf8, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x2f, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x1a, 0xf4, 0xff,
	0x00, 0x00, 0x00, 0x00, 0x61, 0xa0, 0xf4, 0xff, 0x00, 0x00, 0x00, 0x00,
	0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/*
a * b / 2 for 32 bit
clang -O2 -target bpf -m32 -c example/bpf/mul.bpf.c -o prog.o
*/
const unsigned char bpf_mul_optimized[] = { 0xb7, 0x00, 0x00, 0x00, 0x02, 0x00,
					    0x00, 0x00, 0x95, 0x00, 0x00, 0x00,
					    0x00, 0x00, 0x00, 0x00 };

const unsigned char bpf_ufunc_code[] =
	""
	"\xbf\x16\x00\x00\x00\x00\x00\x00\xb7\x01\x00\x00\x6f\x00\x00\x00\x6b\x1a\xcc\xff\x00\x00\x00\x00\xb7"
	"\x01\x00\x00\x68\x65\x6c\x6c\x63\x1a\xc8\xff\x00\x00\x00\x00\xbf\xa1\x00\x00\x00\x00\x00\x00\x07\x01"
	"\x00\x00\xc8\xff\xff\xff\x7b\x1a\xd0\xff\x00\x00\x00\x00\xbf\xa2\x00\x00\x00\x00\x00\x00\x07\x02\x00"
	"\x00\xd0\xff\xff\xff\xb7\x01\x00\x00\x02\x00\x00\x00\x85\x00\x00\x00\x01\x00\x00\x00\x79\x61\x00\x00"
	"\x00\x00\x00\x00\x67\x01\x00\x00\x20\x00\x00\x00\xc7\x01\x00\x00\x20\x00\x00\x00\x7b\x1a\xd0\xff\x00"
	"\x00\x00\x00\xb7\x01\x00\x00\x01\x00\x00\x00\x7b\x1a\xd8\xff\x00\x00\x00\x00\xbf\xa2\x00\x00\x00\x00"
	"\x00\x00\x07\x02\x00\x00\xd0\xff\xff\xff\xb7\x01\x00\x00\x01\x00\x00\x00\x85\x00\x00\x00\x01\x00\x00"
	"\x00\x95\x00\x00\x00\x00\x00\x00\x00";

// disassemble:
// 2 mov r1, 0x1
// 3 mov r2, 0x5
// 4 call 0x3
// 5 stxdw [r10-8], r0
// 6 ldxdw r1, [r10-8]
// 7 mov r2, 0x8
// 8 div r2, r1
// 9 stxdw [r10-16], r2
// 10 exit
const unsigned char bpf_div64_code[] = ""
				       "\x79\x13\x00\x00\x00\x00\x00\x00"
				       "\xb7\x01\x00\x00\x01\x00\x00\x00"
				       "\xb7\x02\x00\x00\x05\x00\x00\x00"
				       "\x85\x00\x00\x00\x03\x00\x00\x00"
				       "\x7b\x0a\xf8\xff\x00\x00\x00\x00"
				       "\x79\xa1\xf8\xff\x00\x00\x00\x00"
				       "\xb7\x02\x00\x00\x08\x00\x00\x00"
				       "\x3f\x12\x00\x00\x00\x00\x00\x00"
				       "\x7b\x2a\xf0\xff\x00\x00\x00\x00"
				       "\x95\x00\x00\x00\x00\x00\x00\x00";

/*

int test()
{
	int a = 1;
	int b = 2;
	if (a + b > 2) {
		return 4;
	} else {
		return 5;
	}
}

0 mov r1, 0x1
1 stxw [r10-8], r1
2 mov r1, 0x2
3 stxw [r10-12], r1
4 ldxw r1, [r10-8]
5 ldxw r2, [r10-12]
6 add r1, r2
7 lsh r1, 0x20
8 arsh r1, 0x20
9 mov r2, 0x3
10 jsgt r2, r1, +4

11 ja +0

12 mov r1, 0x4
13 stxw [r10-4], r1
14 ja +3

15 mov r1, 0x5
16 stxw [r10-4], r1
17 ja +0

18 ldxw r0, [r10-4]
19 exit
20
*/

const unsigned char simple_cond_1[] =
	"\xb7\x01\x00\x00\x01\x00\x00\x00\x63\x1a\xf8\xff\x00\x00\x00\x00\xb7\x01\x00\x00\x02\x00\x00\x00\x63"
	"\x1a\xf4\xff\x00\x00\x00\x00\x61\xa1\xf8\xff\x00\x00\x00\x00\x61\xa2\xf4\xff\x00\x00\x00\x00\x0f\x21"
	"\x00\x00\x00\x00\x00\x00\x67\x01\x00\x00\x20\x00\x00\x00\xc7\x01\x00\x00\x20\x00\x00\x00\xb7\x02\x00"
	"\x00\x03\x00\x00\x00\x6d\x12\x04\x00\x00\x00\x00\x00\x05\x00\x00\x00\x00\x00\x00\x00\xb7\x01\x00\x00"
	"\x04\x00\x00\x00\x63\x1a\xfc\xff\x00\x00\x00\x00\x05\x00\x03\x00\x00\x00\x00\x00\xb7\x01\x00\x00\x05"
	"\x00\x00\x00\x63\x1a\xfc\xff\x00\x00\x00\x00\x05\x00\x00\x00\x00\x00\x00\x00\x61\xa0\xfc\xff\x00\x00"
	"\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00";

/*

int test()
{
	int a = 1;
	if (a) {
		return 1;
	} else {
		return 2;
	}
}

0 mov r1, 0x1
1 stxw [r10-8], r1
2 ldxw r1, [r10-8]
3 jeq r1, 0x0, +4
4 ja +0
5 mov r1, 0x1
6 stxw [r10-4], r1
7 ja +3
8 mov r1, 0x2
9 stxw [r10-4], r1
10 ja +0
11 ldxw r0, [r10-4]
12 exit
13
*/

const unsigned char simple_cond_2[] =
	"\xb7\x01\x00\x00\x01\x00\x00\x00\x63\x1a\xf8\xff\x00\x00\x00\x00\x61\xa1\xf8\xff\x00\x00\x00\x00\x15"
	"\x01\x04\x00\x00\x00\x00\x00\x05\x00\x00\x00\x00\x00\x00\x00\xb7\x01\x00\x00\x01\x00\x00\x00\x63\x1a"
	"\xfc\xff\x00\x00\x00\x00\x05\x00\x03\x00\x00\x00\x00\x00\xb7\x01\x00\x00\x02\x00\x00\x00\x63\x1a\xfc"
	"\xff\x00\x00\x00\x00\x05\x00\x00\x00\x00\x00\x00\x00\x61\xa0\xfc\xff\x00\x00\x00\x00\x95\x00\x00\x00"
	"\x00\x00\x00\x00";

/*
int test()
{
	int a = 1;
	int b = 2;
	int c = a > b;
	return c;
}
0 mov r1, 0x1
1 stxw [r10-4], r1
2 mov r2, 0x2
3 stxw [r10-8], r2
4 ldxw r2, [r10-4]
5 lsh r2, 0x20
6 arsh r2, 0x20
7 ldxw r3, [r10-8]
8 lsh r3, 0x20
9 arsh r3, 0x20
10 jsgt r2, r3, +1
11 mov r1, 0x0
12 stxw [r10-12], r1
13 ldxw r0, [r10-12]
14 exit
15


*/

const unsigned char simple_comp_1[] =
	"\xb7\x01\x00\x00\x01\x00\x00\x00\x63\x1a\xfc\xff\x00\x00\x00\x00\xb7\x02\x00\x00\x02\x00\x00\x00\x63"
	"\x2a\xf8\xff\x00\x00\x00\x00\x61\xa2\xfc\xff\x00\x00\x00\x00\x67\x02\x00\x00\x20\x00\x00\x00\xc7\x02"
	"\x00\x00\x20\x00\x00\x00\x61\xa3\xf8\xff\x00\x00\x00\x00\x67\x03\x00\x00\x20\x00\x00\x00\xc7\x03\x00"
	"\x00\x20\x00\x00\x00\x6d\x32\x01\x00\x00\x00\x00\x00\xb7\x01\x00\x00\x00\x00\x00\x00\x63\x1a\xf4\xff"
	"\x00\x00\x00\x00\x61\xa0\xf4\xff\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00";

/*
int test()
{
	int a = 1;
	int b = 2;
	int c = a < b;
	return c;
}
0 mov r1, 0x1
1 stxw [r10-4], r1
2 mov r2, 0x2
3 stxw [r10-8], r2
4 ldxw r2, [r10-4]
5 lsh r2, 0x20
6 arsh r2, 0x20
7 ldxw r3, [r10-8]
8 lsh r3, 0x20
9 arsh r3, 0x20
10 jsgt r3, r2, +1
11 mov r1, 0x0
12 stxw [r10-12], r1
13 ldxw r0, [r10-12]
14 exit
15
*/
const unsigned char simple_comp_2[] =
	"\xb7\x01\x00\x00\x01\x00\x00\x00\x63\x1a\xfc\xff\x00\x00\x00\x00\xb7\x02\x00\x00\x02\x00\x00\x00\x63"
	"\x2a\xf8\xff\x00\x00\x00\x00\x61\xa2\xfc\xff\x00\x00\x00\x00\x67\x02\x00\x00\x20\x00\x00\x00\xc7\x02"
	"\x00\x00\x20\x00\x00\x00\x61\xa3\xf8\xff\x00\x00\x00\x00\x67\x03\x00\x00\x20\x00\x00\x00\xc7\x03\x00"
	"\x00\x20\x00\x00\x00\x6d\x23\x01\x00\x00\x00\x00\x00\xb7\x01\x00\x00\x00\x00\x00\x00\x63\x1a\xf4\xff"
	"\x00\x00\x00\x00\x61\xa0\xf4\xff\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00";

/*
static void (*print_bpf)(char *str) = (void *)0x2;
int print_and_add1()
{
	char a[] = "hello";
	print_bpf(a);
	return 0;
}

0 mov r1, 0x6f
1 stxh [r10-4], r1
2 mov r1, 0x6c6c6568
3 stxw [r10-8], r1
6 mov r1, r10
7 add r1, 0xfffffff8
8 call 0x2
9 mov r0, 0x0
10 exit
11

*/

const unsigned char call_test_1[] = "\xb7\x01\x00\x00\x6f\x00\x00\x00"
				    "\x6b\x1a\xfc\xff\x00\x00\x00\x00"
				    "\xb7\x01\x00\x00\x68\x65\x6c\x6c"
				    "\x63\x1a\xf8\xff\x00\x00\x00\x00"
				    "\xbf\xa1\x00\x00\x00\x00\x00\x00"
				    "\x07\x01\x00\x00\xf8\xff\xff\xff"
				    "\x8d\x00\x00\x00\x02\x00\x00\x00"
				    "\xb7\x00\x00\x00\x00\x00\x00\x00"
				    "\x95\x00\x00\x00\x00\x00\x00\x00";

/*
static unsigned long (*add_bpf)(unsigned long, unsigned long) = (void *)0x3;
int test()
{
	return add_bpf(2, 3);
}


0 lddw r1, 0x0
1 ldxdw r3, [r1]
2 mov r1, 0x2
3 mov r2, 0x3
4 call 0x3
5 exit
*/

const unsigned char call_test_2[] =
	"\x18\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x79\x13\x00\x00\x00\x00\x00\x00\xb7"
	"\x01\x00\x00\x02\x00\x00\x00\xb7\x02\x00\x00\x03\x00\x00\x00\x8d\x00\x00\x00\x03\x00\x00\x00\x95\x00"
	"\x00\x00\x00\x00\x00\x00";

/*

-- asm
mov32 %r0, 0xf8
lsh32 %r0, 28
# %r0 == 0x80000000
arsh32 %r0, 48
exit
-- result
0xffff8000

*/

const unsigned char arsh32_imm_high[] = "\xb4\x00\x00\x00\xf8\x00\x00\x00"
					"\x64\x00\x00\x00\x1c\x00\x00\x00"
					"\xc4\x00\x00\x00\x30\x00\x00\x00"
					"\x95\x00\x00\x00\x00\x00\x00\x00";

/*

-- asm
ldxdw %r0, [%r1]
be16 %r0
exit
-- mem
11 22 33 44 55 66 77 88
-- result
0x1122

*/

const unsigned char be16_high[] =

	"\x79\x10\x00\x00\x00\x00\x00\x00"
	"\xdc\x00\x00\x00\x10\x00\x00\x00"
	"\x95\x00\x00\x00\x00\x00\x00\x00";

/*
	mov %r0, 12
lddw %r1, 0x100000004
div32 %r0, %r1
exit

*/

const unsigned char div32_high_divisor[] = "\xb7\x00\x00\x00\x0c\x00\x00\x00"
					   "\x18\x01\x00\x00\x04\x00\x00\x00"
					   "\x00\x00\x00\x00\x01\x00\x00\x00"
					   "\x3c\x10\x00\x00\x00\x00\x00\x00"
					   "\x95\x00\x00\x00\x00\x00\x00\x00";

/*
mov %r1, 51

# Create lookup table
stdw [%r10-16], 0xab
stdw [%r10-8], 0xcd

# Load lookup[%r1 % 2]
and %r1, 1
lsh %r1, 3
mov %r2, %r10
add %r2, %r1
ldxdw %r0, [%r2-16]

exit

Expected: 0xcd
*/

const unsigned char stack_1[] =

	"\xb7\x01\x00\x00\x33\x00\x00\x00"
	"\x7a\x0a\xf0\xff\xab\x00\x00\x00"
	"\x7a\x0a\xf8\xff\xcd\x00\x00\x00"
	"\x57\x01\x00\x00\x01\x00\x00\x00"
	"\x67\x01\x00\x00\x03\x00\x00\x00"
	"\xbf\xa2\x00\x00\x00\x00\x00\x00"
	"\x0f\x12\x00\x00\x00\x00\x00\x00"
	"\x79\x20\xf0\xff\x00\x00\x00\x00"
	"\x95\x00\x00\x00\x00\x00\x00\x00";

/*
mov %r1, 67
mov %r0, 0x1
mov %r2, 0x2
jgt %r1, 0x2, L3
L1:
ja exit
L2:
add %r2, 0x1
mov %r0, 0x1
jge %r2, %r1, exit
L3:
mov %r3, %r1
div %r3, %r2
mul %r3, %r2
mov %r4, %r1
sub %r4, %r3
mov %r0, 0x0
jne %r4, 0x0, L2
exit

Expected: 0x1
*/

const unsigned char prime_1[] = "\xb7\x01\x00\x00\x43\x00\x00\x00"
				"\xb7\x00\x00\x00\x01\x00\x00\x00"
				"\xb7\x02\x00\x00\x02\x00\x00\x00"
				"\x25\x01\x04\x00\x02\x00\x00\x00"
				"\x05\x00\x0a\x00\x00\x00\x00\x00"
				"\x07\x02\x00\x00\x01\x00\x00\x00"
				"\xb7\x00\x00\x00\x01\x00\x00\x00"
				"\x3d\x12\x07\x00\x00\x00\x00\x00"
				"\xbf\x13\x00\x00\x00\x00\x00\x00"
				"\x3f\x23\x00\x00\x00\x00\x00\x00"
				"\x2f\x23\x00\x00\x00\x00\x00\x00"
				"\xbf\x14\x00\x00\x00\x00\x00\x00"
				"\x1f\x34\x00\x00\x00\x00\x00\x00"
				"\xb7\x00\x00\x00\x00\x00\x00\x00"
				"\x55\x04\xf6\xff\x00\x00\x00\x00"
				"\x95\x00\x00\x00\x00\x00\x00\x00";

/*
	mov %r1, 1
	mov %r2, 4
	call local func1
	exit
	func1:
	add %r1, %r2
	mov %r0, %r1
	exit
*/

const unsigned char call_local_simple[] = "\xb7\x01\x00\x00\x01\x00\x00\x00"
					  "\xb7\x02\x00\x00\x04\x00\x00\x00"
					  "\x85\x10\x00\x00\x01\x00\x00\x00"
					  "\x95\x00\x00\x00\x00\x00\x00\x00"
					  "\x0f\x21\x00\x00\x00\x00\x00\x00"
					  "\xbf\x10\x00\x00\x00\x00\x00\x00"
					  "\x95\x00\x00\x00\x00\x00\x00\x00";

#endif
