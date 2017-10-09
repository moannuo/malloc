/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 13:59:43 by ademenet          #+#    #+#             */
/*   Updated: 2017/10/09 15:46:31 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "malloc.h"

void		test_large(void)
{
	char 	*test1;
	char 	*test2;
	char 	*test3;
	int		i = 0;

	test1 = (char*)malloc_nts(5000);
	for (i = 0; i < 5000; i++) {
		test1[i] = 'a';
	}
	test2 = (char*)malloc_nts(7000);
	for (i = 0; i < 7000; i++) {
		test2[i] = 'a';
	}
	test3 = (char*)malloc_nts(8000);
	for (i = 0; i < 8000; i++) {
		test2[i] = 'a';
	}
	printf("%s%s%s\n", test1, test2, test3);	
}

void		test_large_loop(void)
{
	int		param = 5000;
	int		max = 50;
	int		i;
	char	*test;

	for (i = 0; i < max; i++) {
		test = (char*)malloc_nts(param);
		test[0] = 'a';
	}
}

void		test_loop_large_random(void)
{
	int		param;
	int		max = 1500;
	int		i;
	char	*test;

	for (i = 0; i < max; i++) {
		param = rand();
		test = (char*)malloc_nts(param);
		test[0] = 'a';
	}
}

void		test_small(void)
{
	char	*test1;
	char	*test2;
	int		i = 0;

	test1 = (char*)malloc_nts(2300);
	for (i = 0; i < 2300; i++) {
		test1[i] = 'a';
	}
	test2 = (char*)malloc_nts(1050);
	for (i = 0; i < 1050; i++) {
		test2[i] = 'b';
	}
	printf("%s%s\n", test1, test2);		
}

void		test_loop_small(void)
{
	int		param = 3467;
	int		max = 32000;
	int		i;
	char	*test;

	for (i = 0; i < max; i++) {
		test = (char*)malloc_nts(param);
		test[0] = 'a';
	}
}

void		test_loop_tinysmall_random(void)
{
	int		param;
	int		max = 1500;
	int		i;
	char	*test;

	for (i = 0; i < max; i++) {
		param = rand() % 4097;
		test = (char*)malloc_nts(param);
		test[0] = 'a';
	}
}

void		test_tiny(void)
{
	char	*test1;
	char	*test2;
	int		i = 0;

	test1 = (char*)malloc_nts(23);
	for (i = 0; i < 23; i++) {
		test1[i] = 'a';
	}
	test2 = (char*)malloc_nts(2);
	for (i = 0; i < 2; i++) {
		test2[i] = 'b';
	}
	printf("%s%s\n", test1, test2);		
}

void		test_loop_tiny_random(void)
{
	int		param;
	int		max = 1500;
	int		i;
	char	*test;

	for (i = 0; i < max; i++) {
		param = rand() % 1025;
		test = (char*)malloc_nts(param);
		test[0] = 'a';
	}
}

void		test_loop_tiny(void)
{
	/* J'ai eu un bug (regle) avec valeurs param = 32 et max = 8191 et + */
	int		param = 1024;
	int		max = 8191;
	int		i;
	char	*test;

	for (i = 0; i < max; i++) {
		test = (char*)malloc_nts(param);
		test[0] = 'a';
	}
}

void		test_loop_tiny_free(void)
{
	int		param = 1024;
	int		max = 3000;
	int		i;
	char	*test1;
	char	*test2;
	char	*test3;

	for (i = 0; i < max; i++) {
		test1 = (char*)malloc_nts(param);
		test1[0] = 'a';
		test2 = (char*)malloc_nts(param);
		test2[0] = 'a';
		test3 = (char*)malloc_nts(param);
		test3[0] = 'a';
		free_nts(test1);
		free_nts(test2);
	}
}

void		test_nul(void)
{
	printf("HEADER_SIZE = %zu\n", HEADER_SIZE);
	printf("TINY_ZONE = %d\n", TINY_ZONE);
	printf("SMALL_ZONE = %d\n", SMALL_ZONE);
	printf("TINY_ZONE %% TINY_RES = %d\n", TINY_ZONE % TINY_RES);
	printf("SMALL_ZONE %% SMALL_RES = %d\n", SMALL_ZONE % SMALL_RES);
	printf("TINY_ZONE / TINY_RES = %d\n", TINY_ZONE / TINY_RES);
	printf("SMALL_ZONE / SMALL_RES = %d\n", SMALL_ZONE / SMALL_RES);
	printf("ALIGN(33, 32) = %d\n", ALIGN(33, 32));
	printf("ALIGN(67, 32) = %d\n", ALIGN(67, 32));
	printf("ALIGN(32, 32) = %d\n", ALIGN(32, 32));
	printf("ALIGN(33, 32) = %d\n", ALIGN(33, 32));
	printf("ALIGN(0, 32) = %d\n", ALIGN(0, 32));
	printf("ALIGN(1, 32) = %d\n", ALIGN(1, 32));
	printf("%zu\n", SIZE_T_MAX);
}

int			main(void)
{
	srand(time(NULL));
	// test_large();
	// test_large_loop();
	// test_tiny();
	// test_small();
	// test_loop_small();
	// test_loop_large_random();
	// test_loop_tinysmall_random();
	test_loop_tiny_free();
	getchar();
	// test_loop_tiny_random();
	// test_loop_tiny();
	// show_mem_alloc();
	show_mem_alloc_all();
	// test_nul();
	return (0);
}
