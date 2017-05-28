/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 00:08:09 by obelange          #+#    #+#             */
/*   Updated: 2016/11/12 00:08:11 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main()
{	
	printf("\n\n\n");
	
	// setlocale( LC_ALL, "");
	// char s[9] =  {'s', '4', 's', '5', '6', '5', '2', '3', '\0'};
	char *s;
	char *s0 = "this is a plain string";
	// "h", "l", "j", "z", "hh", "ll"
	//h, j, l, hh
	char *s1 = "ft_printf->%*d\n";
	char *s2 = "this is string number";
	char *s3 = "we call this one %s";	
	short k = 270;
	intmax_t f = -4;


	printf("\n");

	// printf("( %d )\n", ft_printf("ft_printf: -->%c%c<--", 0,0));	
	// printf("( %d )\n",	   printf("   printf: -->%c%c<--", 0,0));

	// wide char test leaks
	// ft_printf("ft_printf: -->%S<--\n", L"00 € 00");	
   	   // printf("   printf: -->%S<--\n", L"00 € 00");


	// ft_printf("ft_printf: -->%C<--\n", L'€');	

	// ft_printf("ft_printf: -->%s<--\n", "cool");	

	// * 
	// ft_printf("ft_printf: -->%*.*d<--\n", 10, 3, 99);	
   	   // printf("   printf: -->%*.*d<--\n", 10, 3, 99);

	// binary
	// ft_printf("ft_printf: -->%b<--\n", 4000);

	// %
	// ft_printf("ft_printf: -->%%<--\n");

	// kills malloc	
	//    printf("-->%#08x<--", 42);
	// ft_printf("-->%#08x<--", 42);
	// seg fault
	//    printf("   printf: %%+d->%+d\n", 99);	
	// ft_printf("ft_printf: %%+d->%+d\n", 99);	


	// test 44
	// conflict between 0 flag, hashtag, and field width
	// ft_printf("ft_printf: -->%#08x<--\n", 42);	
	   // printf("   printf: -->%#08x<--\n", 42);
	

	// test 0104 
	// intmax + 1 should be a flipped d
  	// ft_printf("ft_printf: -->%d<--\n", 2147483648);	
	  //  printf("   printf: -->%d<--\n", 2147483648);  

	// test 0087
	// breaks malloc hash and fieldwidth modifiers
  	// ft_printf("ft_printf: -->%#6o<--\n", 2500);
	   // printf("   printf: -->%#6o<--\n", 2500);  	
		
	// test 0088
    // breaks malloc hash and fieldwidth modifiers
  	// ft_printf("ft_printf: -->%-#6o<--\n", 2500);
  	   // printf("   printf: -->%-#6o<--\n", 2500);  

 	// test 0095 	
 	// break malloc hash and 0
	// ft_printf("ft_printf: -->%#.o %#.0o<--\n", 0, 0);  	   
  	   // printf("   printf: -->%#.o %#.0o<--\n", 0, 0);    

	// test 0059
	// null string seg faulting
	// ft_printf("ft_printf: -->%10s is a string<--\n", "");  	   
  	   // printf("   printf: -->%10s is a string<--\n", "");    		  

	// test 0060
	// null string seg faulting
	// ft_printf("ft_printf: -->%.2s is a string<--\n", "");  	   
  	   // printf("   printf: -->%.2s is a string<--\n", "");    		  	  

	// test 0061
	// null string seg faulting
	// ft_printf("ft_printf: -->%5.2s is a string<--\n", "");  	   
  	   // printf("   printf: -->%5.2s is a string<--\n", "");    		  	  

	// test 0065
	// null string seg faulting
	// ft_printf("ft_printf: -->%-10s is a string<--\n", "");  	   
  	   // printf("   printf: -->%-10s is a string<--\n", "");    		  	  

	// test 0066
	// null string seg faulting
	// ft_printf("ft_printf: -->%-.2s is a string<--\n", "");  	   
  	   // printf("   printf: -->%-.2s is a string<--\n", "");    		  	  

	// test 0067
	// null string seg faulting	
	// ft_printf("ft_printf: -->%-5.2s is a string<--\n", "");  	   
  	   // printf("   printf: -->%-5.2s is a string<--\n", "");    		  	  

	// test 0079 (char)
	// printf("( %d )\n", ft_printf("ft_printf: -->%c<--", 0));  	
  	// printf("( %d )\n", printf("   printf: -->%c<--", 0));    		  	    

	// // test 0080 (char)
	// ft_printf("ft_printf: -->%2c<--\n", 0);  	   
 //  	   printf("   printf: -->%2c<--\n", 0);    		  	    

 //    // test 0074 (NULL)
	// ft_printf("ft_printf: -->%.2c<--\n", NULL);  	   
 //  	   printf("   printf: -->%.2c<--\n", NULL);    		  	  
  

	// // test 0081 (char)
	// printf("( %d )\n", ft_printf("ft_printf: -->null %c and %c text<--", 0, 0));  	   
  	// printf("( %d )\n",    printf("   printf: -->null %c and %c text<--", 0, 0));

	// // test 0082 (char)
	// ft_printf("ft_printf: -->% c<--\n", 0);  	   
  	   // printf("   printf: -->% c<--\n", 0);   
  
	// // test 0113 (int)
	// // sometimes segfault
	// ft_printf("ft_printf: -->% +d<--\n",  42);
 //  	   printf("   printf: -->% +d<--\n",  42);  

	// // test 0131 (int)
	// ft_printf("ft_printf: -->%05d<--\n", -42);
 //  	   printf("   printf: -->%05d<--\n", -42);  	

	// // test 0132 (int)
	// ft_printf("ft_printf: -->%0+5d<--\n", -42);
 //  	   printf("   printf: -->%0+5d<--\n", -42);  

	// // test 0167 (int)
	// ft_printf("ft_printf: -->% 10.5d<--\n", 4242);
 //  	   printf("   printf: -->% 10.5d<--\n", 4242);  

	// // test 0168 (int)
	// ft_printf("ft_printf: -->%+10.5d<--\n", 4242);
 //  	   printf("   printf: -->%+10.5d<--\n", 4242);  
	
	// // test 0169 (int)
	// ft_printf("ft_printf: -->%-+10.5d<--\n", 4242);
 //  	   printf("   printf: -->%-+10.5d<--\n", 4242);  

	// while (1)	
	// {
	// // test 0119 (int)
	// printf("\n\n\n\n\n");
	// ft_printf("ft_printf: -->%+  d<--\n", 42);
	//    printf("   printf: -->%+  d<--\n", 42);  
	// }




	// // test 0119 (int)
	// ft_printf("ft_printf: -->%+ d<--\n", 42);
	//    printf("   printf: -->%+ d<--\n", 42);  

	// // test 0119 (int)
	// ft_printf("ft_printf: -->%+    d<--\n", 42);
	//    printf("   printf: -->%+    d<--\n", 42);  

	// test 0007 
	// ft_printf("ft_printf: -->%5%<--\n");
	   // printf("   printf: -->%5%<--\n");

	// // test 0008 
	// ft_printf("ft_printf: -->%-5%<--\n");
	   // printf("   printf: -->%-5%<--\n");

	// // test 0001 
 //  	printf("( %d )\n",  ft_printf(""));
	// printf("( %d )\n",     printf(""));

	// // test 0047 (int)
	// ft_printf("ft_printf: -->%.x %.0x<--\n", 0, 0);
	//    printf("   printf: -->%.x %.0x<--\n", 0, 0);


	// // test 0046 (int)
	// ft_printf("ft_printf: -->%#.x %#.0x<--\n", 0, 0);
	//    printf("   printf: -->%#.x %#.0x<--\n", 0, 0);



	// // test 0048 (int)
	// ft_printf("ft_printf: -->%5.x %5.0x<--\n", 0, 0);
	//    printf("   printf: -->%5.x %5.0x<--\n", 0, 0);



	// // // test 0094 (int)
 //  	ft_printf("ft_printf: -->%5.o %5.0o<--\n", 0, 0);
	//    printf("   printf: -->%5.o %5.0o<--\n", 0, 0);
  

	// // test 0095 (int)
 //  	ft_printf("ft_printf: -->%#.o %#.0o<--\n", 0, 0);
	//    printf("   printf: -->%#.o %#.0o<--\n", 0, 0);


	// // test 0176 (int)
 //  	ft_printf("ft_printf: -->%5.d %5.0d<--\n", 0, 0);
	//    printf("   printf: -->%5.d %5.0d<--\n", 0, 0);



  	
  	// c
   	// ft_printf("ft_printf: -->%c\n", 42);
   	//    printf("   printf: -->%c\n", 42);
    
    // ft_printf("ft_printf: -->Kashim a %c histoires à raconter\n", 1001);
    //    printf("   printf: -->Kashim a %c histoires à raconter\n", 1001);
    
    // ft_printf("ft_printf: -->Il fait au moins %c\n", -8000);
    //    printf("   printf: -->Il fait au moins %c\n", -8000);
    
    // ft_printf("ft_printf: -->%c\n", -0);
    //    printf("   printf: -->%c\n", -0);
    
    // ft_printf("ft_printf: -->%c\n", 0);
    //    printf("   printf: -->%c\n", 0);
    
    // ft_printf("ft_printf: -->%c\n", INT_MAX);
    //    printf("   printf: -->%c\n", INT_MAX);
    
    // ft_printf("ft_printf: -->%c\n", 'c');
    //    printf("   printf: -->%c\n", 'c');
    
    // ft_printf("ft_printf: -->%c\n", '\n');
    //    printf("   printf: -->%c\n", '\n');
    
    // ft_printf("ft_printf: -->%c\n", 'l');
    //    printf("   printf: -->%c\n", 'l');
    
    // ft_printf("ft_printf: -->%c\n", 'y');
    //    printf("   printf: -->%c\n", 'y');
    
    // ft_printf("ft_printf: -->%c\n", ' ');
    //    printf("   printf: -->%c\n", ' ');
    
    // ft_printf("ft_printf: -->%c\n", 'e');
    //    printf("   printf: -->%c\n", 'e');
    
    // ft_printf("ft_printf: -->%c\n", 's');
    //    printf("   printf: -->%c\n", 's');
    
    // ft_printf("ft_printf: -->%c\n", 't');
    //    printf("   printf: -->%c\n", 't');
    
    // ft_printf("ft_printf: -->%c\n", ' ');
    //    printf("   printf: -->%c\n", ' ');
    
    // ft_printf("ft_printf: -->%c\n", 'f');
    //    printf("   printf: -->%c\n", 'f');
    
    // ft_printf("ft_printf: -->%c\n", 'a');
    //    printf("   printf: -->%c\n", 'a');
    
    // ft_printf("ft_printf: -->%c\n", 'n');
    //    printf("   printf: -->%c\n", 'n');
    
    // ft_printf("ft_printf: -->%c\n", 't');
    //    printf("   printf: -->%c\n", 't');
    
    // ft_printf("ft_printf: -->%c\n", 'a');
    //    printf("   printf: -->%c\n", 'a');
    
    // ft_printf("ft_printf: -->%c\n", 's');
    //    printf("   printf: -->%c\n", 's');
    
    // ft_printf("ft_printf: -->%c\n", 't');
    //    printf("   printf: -->%c\n", 't');    
    
    // ft_printf("ft_printf: -->%c\n", 'i');
    //    printf("   printf: -->%c\n", 'i');
    
    // ft_printf("ft_printf: -->%c\n", 'q');
    //    printf("   printf: -->%c\n", 'q');
    
    // ft_printf("ft_printf: -->%c\n", 'u');
    //    printf("   printf: -->%c\n", 'u');
    
    // ft_printf("ft_printf: -->%c\n", 'e');
    //    printf("   printf: -->%c\n", 'e');
    
    // ft_printf("ft_printf: -->%c\n", '!');
    //    printf("   printf: -->%c\n", '!');
    
    // ft_printf("ft_printf: -->%c\n", '\r');
    //    printf("   printf: -->%c\n", '\r');
    
    // ft_printf("ft_printf: -->%c\n", '\t');
    //    printf("   printf: -->%c\n", '\t');

    // ft_printf("ft_printf: -->%C\n", L'à');
    //    printf("   printf: -->%C\n", L'à');
       
    // mix 2
    // ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");

    // d   printf: -->
    // ft_printf("ft_printf: -->%D\n", 42);
    //    printf("   printf: -->%D\n", 42);
       
    // ft_printf("ft_printf: -->Kashim a %D histoires à raconter\n", 1001);
    //    printf("   printf: -->Kashim a %D histoires à raconter\n", 1001);
       
    // ft_printf("ft_printf: -->Il fait au moins %D\n", -8000);
    //    printf("   printf: -->Il fait au moins %D\n", -8000);
    
    // ft_printf("ft_printf: -->%D\n", -0);
    //    printf("   printf: -->%D\n", -0);
    
    // ft_printf("ft_printf: -->%D\n", 0);
    //    printf("   printf: -->%D\n", 0);
    
    // ft_printf("ft_printf: -->%D\n", INT_MAX);
    //    printf("   printf: -->%D\n", INT_MAX);
    
    // ft_printf("ft_printf: -->%D\n", INT_MIN);
    //    printf("   printf: -->%D\n", INT_MIN);
    
    // ft_printf("ft_printf: -->%D\n", INT_MIN - 1);
    //    printf("   printf: -->%D\n", INT_MIN - 1);
    
    // ft_printf("ft_printf: -->%D\n", INT_MAX + 1);
    //    printf("   printf: -->%D\n", INT_MAX + 1);
    
    // ft_printf("ft_printf: -->%%D 0000042 == |%D|\n", 0000042);
    //    printf("   printf: -->%%D 0000042 == |%D|\n", 0000042);
    
    // ft_printf("ft_printf: -->%%D \t == |%D|\n", '\t');
    //    printf("   printf: -->%%D \t == |%D|\n", '\t');
    
    // ft_printf("ft_printf: -->%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');
    //    printf("   printf: -->%%D Lydie == |%D|\n", 'L'+'y'+'d'+'i'+'e');

    // precision	
	// ft_printf("ft_printf: -->%04.2i<--\n", 42);
	   // printf("   printf: -->%04.2i<--\n", 42);

	//space
   	// ft_printf("ft_printf: -->% 4i<--\n", 42);
	   // printf("   printf: -->% 4i<--\n", 42);

	// ft_printf("ft_printf: -->% 4i<--\n", 4200);
	   // printf("   printf: -->% 4i<--\n", 4200);

	// ft_printf("ft_printf: -->% i<--\n", 42);
	   // printf("   printf: -->% i<--\n", 42);


	// ft_printf("ft_printf->%% 4i 42 == |% 4i|\n", 42);
	//    printf("   printf->%% 4i 42 == |% 4i|\n", 42);
	// ft_printf("ft_printf->%%04.2i 42 == |%04.2i|\n", 42);
	//    printf("   printf->%%04.2i 42 == |%04.2i|\n", 42);
	// ft_printf("ft_printf->Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");
	//    printf("   printf->Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'à', "Ly", 2, 10, 10000, '\n', "ôHohoho");




	// my problem children
	// ft_printf("ft_printf: #- +2d->%#- +2d<-\n", 17);	
	// printf("   printf: #- +2d->%#- +2d<-\n", 17);

	// ft_printf("ft_printf: #- +3d->%#- +3d<-\n", 17);	
	// printf("   printf: #- +3d->%#- +3d<-\n", 17);	
	
	// ft_printf("ft_printf: #- +4d->%#- +4d<-\n", 17);	
	// printf("   printf: #- +4d->%#- +4d<-\n", 17);	
	
	// ft_printf("ft_printf: #- +10d->%#- +10d<-\n", 17);	
	// printf("   printf: #- +10d->%#- +10d<-\n", 17);	

	// printf("   printf: %%#d->%#d\n", 99);
	// printf("   printf: %%#o->%#o\n", 99);
	// printf("   printf: %%#09.o->%#09.o\n", 99);
	// printf("   printf: %%#x->%#x\n", -44);		
	// printf("   printf: %%#x->%#x\n", 0);		
	// printf("   printf: %%#.4x->%#.4x\n", 99);
	// printf("   printf: %%#7.3x->%#7.3x\n", 99);
	// printf("   printf: %%+#-02.7d->%+#-02.7d<-\n", 99);
 //    printf("   printf: %%#02.7o->%#02.7o\n", 99);
 //    printf("   printf:  %%#2.7o->%#2.7o\n", 99);
	// printf("   printf: %%#02.7x->%#02.7x\n", 15);	

	// printf("numerals mfw\n");
	//       printf("   printf: %%d->%d\n", 99);		
	//    ft_printf("ft_printf: %%d->%d\n", 99);
	//    	   printf("   printf: %%#d->%#d\n", 99);
	//    	ft_printf("ft_printf: %%#d->%#d\n", 99);
	//       printf("   printf: %% d->% d\n", 99);	
	//    ft_printf("ft_printf: %% d->% d\n", 99);	
	//       printf("   printf: %% d->% d\n", -99);	
	//    ft_printf("ft_printf: %% d->% d\n", -99);	
	//       printf("   printf: %%+d->%+d\n", 99);	
	//    ft_printf("ft_printf: %%+d->%+d\n", 99);	
	//       printf("   printf: %%+d->%+d\n", -99);
	//    ft_printf("ft_printf: %%+d->%+d\n", -99);
	//       printf("   printf: %% +d->% +d\n", 99);	
	//    ft_printf("ft_printf: %% +d->% +d\n", 99);	
	//       printf("   printf: %% +d->% +d\n", -99);						
	//    ft_printf("ft_printf: %% +d->% +d\n", -99);						
	//       printf("   printf: %%0d->%0d\n", 99);	
	//    ft_printf("ft_printf: %%0d->%0d\n", 99);	

	//       printf("   printf: %%-0d->%-0d<-\n", 99);	
	//    ft_printf("ft_printf: %%-0d->%-0d<-\n", 99);	
	//       printf("   printf: %%05d->%05d\n", 99);	
	//    ft_printf("ft_printf: %%05d->%05d\n", 99);	
	//       printf("   printf: %%05.d->%05.d\n", 99);	
	//    ft_printf("ft_printf: %%05.d->%05.d\n", 99);	
	//       printf("   printf: %%05.0d->%05.0d\n", 99);	
	//    ft_printf("ft_printf: %%05.0d->%05.0d\n", 99);	
	//       printf("   printf: %%-05d->%-05d<-\n", 99);	
	//    ft_printf("ft_printf: %%-05d->%-05d<-\n", 99);	
	//       printf("   printf: %%#-05d->%#-05d<-\n", 99);
	//    ft_printf("ft_printf: %%#-05d->%#-05d<-\n", 99);
	//       printf("   printf: %% -05d->% -05d<-\n", 99);
	//    ft_printf("ft_printf: %% -05d->% -05d<-\n", 99);

	//       printf("   printf: %%+-05d->%+-05d<-\n", 99);
	//    ft_printf("ft_printf: %%+-05d->%+-05d<-\n", 99);
	//       printf("   printf: %%02.7d->%02.7d\n", 99);		
	//    ft_printf("ft_printf: %%02.7d->%02.7d\n", 99);		
	//       printf("   printf: %%-02.7d->%-02.7d<-\n", 99);	
	//    ft_printf("ft_printf: %%-02.7d->%-02.7d<-\n", 99);	
	//       printf("   printf: %%#02.7d->%#02.7d\n", 99);		
	//    ft_printf("ft_printf: %%#02.7d->%#02.7d\n", 99);		
	//       printf("   printf: %%#-02.7d->%#-02.7d<-\n", 99);	
	//    ft_printf("ft_printf: %%#-02.7d->%#-02.7d<-\n", 99);	
	//       printf("   printf: %% #-02.7d->% #-02.7d<-\n", 99);	
	//    ft_printf("ft_printf: %% #-02.7d->% #-02.7d<-\n", 99);	

	//       printf("   printf: %%+ #-02.7d->%+ #-02.7d<-\n", 99);	
	//    ft_printf("ft_printf: %%+ #-02.7d->%+ #-02.7d<-\n", 99);	
	//       printf("   printf: %% +#-02.7d->% +#-02.7d<-\n", 99);	
	//    ft_printf("ft_printf: %% +#-02.7d->% +#-02.7d<-\n", 99);	
	//       printf("   printf: %%+#-015.7d->%+#-015.7d<-\n", 99);	
	//    ft_printf("ft_printf: %%+#-015.7d->%+#-015.7d<-\n", 99);	
	//       printf("   printf: %%+-015.7d->%+-015.7d<-\n", 99);	
	//    ft_printf("ft_printf: %%+-015.7d->%+-015.7d<-\n", 99);	
	//    	printf("\n");
	   	
	//       printf("   printf: %%o->%o\n", 99);
	//    ft_printf("ft_printf: %%o->%o\n", 99);
	//       printf("   printf: %%#o->%#o\n", 99);
	//    ft_printf("ft_printf: %%#o->%#o\n", 99);
	//       printf("   printf: %% o->% o\n", 99);
	//    ft_printf("ft_printf: %% o->% o\n", 99);
	//       printf("   printf: %% o->% o\n", -99);
	//    ft_printf("ft_printf: %% o->% o\n", -99);
	//       printf("   printf: %%+o->%+o\n", 99);
	//    ft_printf("ft_printf: %%+o->%+o\n", 99);
	//       printf("   printf: %%+o->%+o\n", -99);
	//    ft_printf("ft_printf: %%+o->%+o\n", -99);
	//       printf("   printf: %% +o->% +o\n", 99);
	//    ft_printf("ft_printf: %% +o->% +o\n", 99);
	//       printf("   printf: %% +o->% +o\n", -99);
	//    ft_printf("ft_printf: %% +o->% +o\n", -99);
	//       printf("   printf: %%#.3o->%#.3o\n", 99);
	//    ft_printf("ft_printf: %%#.3o->%#.3o\n", 99);
	//       printf("   printf: %%#3.3o->%#3.3o\n", 99);
	//    ft_printf("ft_printf: %%#3.3o->%#3.3o\n", 99);
	//       printf("   printf: %%0o->%0o\n", 99);
	//    ft_printf("ft_printf: %%0o->%0o\n", 99);
	//       printf("   printf: %%-0o->%-0o<-\n", 99);
	//    ft_printf("ft_printf: %%-0o->%-0o<-\n", 99);
	//       printf("   printf: %%05o->%05o\n", 99);
	//    ft_printf("ft_printf: %%05o->%05o\n", 99);
	//       printf("   printf: %%-05o->%-05o<-\n", 99);
	//    ft_printf("ft_printf: %%-05o->%-05o<-\n", 99);
	//       printf("   printf: %%02.7o->%02.7o\n", 99);
	//    ft_printf("ft_printf: %%02.7o->%02.7o\n", 99);
	//       printf("   printf: %%-02.7o->%-02.7o<-\n", 99);
	//    ft_printf("ft_printf: %%-02.7o->%-02.7o<-\n", 99);
	//       printf("   printf: %%#02.7o->%#02.7o\n", 99);
	//    ft_printf("ft_printf: %%#02.7o->%#02.7o\n", 99);
	//       printf("   printf: %%#-02.7o->%#-02.7o<-\n", 99);
	//    ft_printf("ft_printf: %%#-02.7o->%#-02.7o<-\n", 99);
	//       printf("   printf: %%#+-02.7o->%#+-02.7o<-\n", 99);
	//    ft_printf("ft_printf: %%#+-02.7o->%#+-02.7o<-\n", 99);
	//       printf("   printf: %%#+-02.3o->%#+-02.3o<-\n", 99);
	//    ft_printf("ft_printf: %%#+-02.3o->%#+-02.3o<-\n", 99);
	//       printf("   printf: %%# +-02.3o->%# +-02.3o<-\n", 99);
	//    ft_printf("ft_printf: %%# +-02.3o->%# +-02.3o<-\n", 99);
	//    	printf("\n");


	//       printf("   printf: %%x->%x\n", -44);				   
	//    ft_printf("ft_printf: %%x->%x\n", -44);				   
	//       printf("   printf: %%#x->%#x\n", -44);				   
	//    ft_printf("ft_printf: %%#x->%#x\n", -44);				   
	//       printf("   printf: %%#x->%#x\n", 0);				   
	//    ft_printf("ft_printf: %%#x->%#x\n", 0);				   
	//       printf("   printf: %% x->% x\n", 44);				   
	//    ft_printf("ft_printf: %% x->% x\n", 44);				   
	//       printf("   printf: %% x->% x\n", -44);	
	//    ft_printf("ft_printf: %% x->% x\n", -44);	
	//       printf("   printf: %%+x->%+x\n", 44);	
	//    ft_printf("ft_printf: %%+x->%+x\n", 44);	
	//       printf("   printf: %%+x->%+x\n", -44);	
	//    ft_printf("ft_printf: %%+x->%+x\n", -44);	
	//       printf("   printf: %%+ x->%+ x\n", 44);	
	//    ft_printf("ft_printf: %%+ x->%+ x\n", 44);	
	//       printf("   printf: %%+ x->%+ x\n", -44);			   
	//    ft_printf("ft_printf: %%+ x->%+ x\n", -44);			   
	//       printf("   printf: %%#.3x->%#.3x\n", 99);
	//    ft_printf("ft_printf: %%#.3x->%#.3x\n", 99);
	//       printf("   printf: %%#.3x->%.3x\n", 9);
	//    ft_printf("ft_printf: %%#.3x->%.3x\n", 9);
	//       printf("   printf: %%#3.3x->%#3.3x\n", 99);
	//    ft_printf("ft_printf: %%#3.3x->%#3.3x\n", 99);
	//       printf("   printf: %%0x->%0x\n", -44);	
	//    ft_printf("ft_printf: %%0x->%0x\n", -44);	
	//       printf("   printf: %%-0x->%-0x<-\n", -44);	
	//    ft_printf("ft_printf: %%-0x->%-0x<-\n", -44);	
	//       printf("   printf: %%05x->%05x\n", 15);
	//    ft_printf("ft_printf: %%05x->%05x\n", 15);
	//       printf("   printf: %%-05x->%-05x<-\n", 15);
	//    ft_printf("ft_printf: %%-05x->%-05x<-\n", 15);
	//       printf("   printf: %%02.7x->%02.7x\n", 15);				   
	//    ft_printf("ft_printf: %%02.7x->%02.7x\n", 15);				   
	//       printf("   printf: %%-02.7x->%-02.7x<-\n", 15);	
	//    ft_printf("ft_printf: %%-02.7x->%-02.7x<-\n", 15);	
	//       printf("   printf: %%#02.7x->%#02.7x\n", 15);				   
	//    ft_printf("ft_printf: %%#02.7x->%#02.7x\n", 15);				   
	//       printf("   printf: %%#-02.7x->%#-02.7x<-\n", 15);		
	//    ft_printf("ft_printf: %%#-02.7x->%#-02.7x<-\n", 15);		
 //   	printf("\n");

	// printf("pointer mfw\n");
	//       printf("   printf: %%p->%p\n", s0); 	   
	//    ft_printf("ft_printf: %%p->%p\n", s0); 	   
	//       printf("   printf: %%#p->%#p\n", s0);
	//    ft_printf("ft_printf: %%#p->%#p\n", s0);
	//       printf("   printf: %% p->% p\n", s0); 
	//    ft_printf("ft_printf: %% p->% p\n", s0); 
	//       printf("   printf: %%+p->%+p\n", s0); 
	//    ft_printf("ft_printf: %%+p->%+p\n", s0); 
	//       printf("   printf: %%0p->%0p\n", s0);			
	//    ft_printf("ft_printf: %%0p->%0p\n", s0);			
	//       printf("   printf: %%-0p->%-0p<-\n", s0);	
	//    ft_printf("ft_printf: %%-0p->%-0p<-\n", s0);	
	//       printf("   printf: %%05p->%05p\n", s0);	
	//    ft_printf("ft_printf: %%05p->%05p\n", s0);	
	//       printf("   printf: %%-05p->%-05p<-\n", s0);	
	//    ft_printf("ft_printf: %%-05p->%-05p<-\n", s0);	
	//       printf("   printf: %%02.7p->%02.7p\n", s0);			
	//    ft_printf("ft_printf: %%02.7p->%02.7p\n", s0);			
	//       printf("   printf: %%-02.7p->%-02.7p<-\n", s0);	
	//     ft_printf("ft_printf: %%-02.7p->%-02.7p<-\n", s0);	
 //  	printf("\n");


	// printf("char mfw\n");
	//       printf("   printf: %%c->%c\n", 'f');
	//    ft_printf("ft_printf: %%c->%c\n", 'f');
	//       printf("   printf: %%#c->%#c\n", 'f');
	//    ft_printf("ft_printf: %%#c->%#c\n", 'f');
	//       printf("   printf: %% c->% c\n", 'f');
	//    ft_printf("ft_printf: %% c->% c\n", 'f');
	//       printf("   printf: %%+c->%+c\n", 'f');
	//    ft_printf("ft_printf: %%+c->%+c\n", 'f');
	//       printf("   printf: %%0c->%0c\n", 'f');	 
	//    ft_printf("ft_printf: %%0c->%0c\n", 'f');	 
	//       printf("   printf: %%-0c->%-0c<-\n", 'f');	
	//    ft_printf("ft_printf: %%-0c->%-0c<-\n", 'f');	
	//       printf("   printf: %%07c->%07c\n", 'f');	
	//    ft_printf("ft_printf: %%07c->%07c\n", 'f');	
	//       printf("   printf: %%-07c->%-07c<-\n", 'f');	
	//    ft_printf("ft_printf: %%-07c->%-07c<-\n", 'f');	
	//       printf("   printf: %%06.10c->%06.10c\n", 'f');	 
	//    ft_printf("ft_printf: %%06.10c->%06.10c\n", 'f');	 
	//       printf("   printf: %%-06.10c->%-06.10c<-\n", 'f');	
	//    ft_printf("ft_printf: %%-06.10c->%-06.10c<-\n", 'f');	
 //   	printf("\n");


	// printf("char* mfw\n");
	//       printf("   printf: %%s->%s\n", "ssss");
	//    ft_printf("ft_printf: %%s->%s\n", "ssss");
	//       printf("   printf: %%#s->%#s\n", "ssss");
	//    ft_printf("ft_printf: %%#s->%#s\n", "ssss");
	//       printf("   printf: %% s->% s\n", "ssss");
	//    ft_printf("ft_printf: %% s->% s\n", "ssss");
	//       printf("   printf: %%+s->%+s\n", "ssss");
	//    ft_printf("ft_printf: %%+s->%+s\n", "ssss");
	//       printf("   printf: %%0s->%0s\n", "ssss");		
	//    ft_printf("ft_printf: %%0s->%0s\n", "ssss");		
	//       printf("   printf: %%-0s->%-0s<-\n", "ssss");
	//    ft_printf("ft_printf: %%-0s->%-0s<-\n", "ssss");
	//       printf("   printf: %%07s->%07s\n", "ssss");	
	//    ft_printf("ft_printf: %%07s->%07s\n", "ssss");	
	//       printf("   printf: %%-07s->%-07s<-\n", "ssss");	
	//    ft_printf("ft_printf: %%-07s->%-07s<-\n", "ssss");	
	//       printf("   printf: %%06.10s->%06.10s\n", "ssss");		
	//    ft_printf("ft_printf: %%06.10s->%06.10s\n", "ssss");		
	//       printf("   printf: %%-06.10s->%-06.10s<-\n", "ssss");		
	//    ft_printf("ft_printf: %%-06.10s->%-06.10s<-\n", "ssss");		
 //   	printf("\n");

	return (0);
}