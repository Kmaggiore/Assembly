#################################################################################################
#
#Kendra Maggiore, CS 2318-253, Assignment 2 Part 1 Program C
#
#Description - Declare global array and then swap the order and output the neww order to screen
#################################################################################################
#
########################### data segment ########################################################

			.data
array:			.word 44,99,33,11,55, # int array[4] = {111, 222, 333, 444} 
values:			.asciiz "The values in array are: "	
swapValues:		.asciiz "The values in array after swapping are: "	
comma:			.asciiz ", "

############################ code segment ######################################################
			.text
			.globl main

main:
			
			
			li $v0, 4
			la $a0, values 		#printing values string
			syscall
			
			li $v0, 1
			la $t0, array		#printing array 1st element
			lw $a0, 0($t0)
			syscall
			
			li $v0,4
			la $a0, comma		# print comma
			syscall
			
			li $v0, 1
			la $t0, array		#print array 2nd element
			lw $a0, 4($t0)
			syscall
			
			li $v0,4
			la $a0, comma		#print comma
			syscall
			
			li $v0, 1
			la $t0, array		#print array 3rd element
			lw $a0, 8($t0)
			syscall
			
			li $v0,4
			la $a0, comma		#print comma
			syscall
			
			li $v0, 1
			la $t0, array		#print array 4th element
			lw $a0, 12($t0)
			syscall
			
			li $v0,4
			la $a0, comma		#print comma
			syscall
			
			li $v0, 1
			la $t0, array		#print array 5th element
			lw $a0, 16($t0)
			syscall
			
			li $v0, 11
			li $a0, '\n'		#print a newline
			syscall
			
			li $v0, 4
			la $a0, swapValues	#print swapValues string
			syscall
			
			lw $t1, 0($t0)
			lw $t2, 12($t0)		#swap 1st and 4th elements of the array
			sw $t1, 12($t0)
			sw $t2, 0($t0)
			
			lw $t3, 4($t0)
			lw $t4, 16($t0)		#swap 2nd and 5th elements of the array
			sw $t3, 16($t0)
			sw $t4, 4($t0)
			
			li $v0, 1
			la $t0, array		#prints array 5th element
			lw $a0, 16($t0)
			syscall
			
			li $v0,4
			la $a0, comma		#prints comma
			syscall
			
			li $v0, 1
			la $t0, array		#prints array 4th element
			lw $a0, 12($t0)
			syscall
			
			li $v0,4
			la $a0, comma		#prints comma
			syscall
			
			li $v0, 1
			la $t0, array		#prints array 3rd element
			lw $a0, 8($t0)
			syscall
			
			li $v0,4
			la $a0, comma		#prints comma
			syscall
			
			li $v0, 1
			la $t0, array		#prints array 2nd element
			lw $a0, 4($t0)
			syscall
			
			li $v0,4
			la $a0, comma		#prints comma
			syscall
			
			li $v0, 1
			la $t0, array		#prints array 1st element
			lw $a0, 0($t0)
			syscall
			
			li $v0, 11
			li $a0, '\n'		#print a newline
			syscall
			
			li $v0, 10 		#exit
			syscall