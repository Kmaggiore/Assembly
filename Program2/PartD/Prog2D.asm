##########################################################################
#
#Kendra Maggiore, CS 2318-253, Assignment 2 Part 1 Program D.
#
#Function Description - Evaluates course score based on 2 exam scores and 
#a final exam
#
##########################################################################
#
############################ data segment ################################

		.data
exam1:		.asciiz "Please, enter score for Exam 1: "
exam2:		.asciiz "Please, enter score for Exam 2: "
finalExam:	.asciiz "Please, enter score for Final Exam: "
average:	.asciiz "Your, final score for the class: "


############################ code segment ################################

			.text
			.globl main
main:
			
			li $v0, 4
			la $a0, exam1			#promot for input of exam 1
			syscall
			
			li $v0, 5			#read input for exam 1
			syscall
			move $t0, $v0			#save exam 1 score to $t0
			
			li $v0, 11
			li $a0, '\n' 			# newline spacing
			syscall
			
			li $v0, 4
			la $a0, exam2			#promot for input of exam 2
			syscall
			
			li $v0, 5			#read input for exam 2
			syscall
			move $t1, $v0			#save exam 2 score to $t1
			
			li $v0, 11
			li $a0, '\n' 			# newline spacing
			syscall
			
			li $v0, 4
			la $a0, finalExam		#promot for input of final exam
			syscall
			
			li $v0, 5			#read input for final exam
			syscall
			move $t2, $v0			#save final exam score to $t2
			
			li $v0, 11
			li $a0, '\n' 			# newline spacing
			syscall
			
			li $t3, 115			#load $t3 with 115
			li $t4, 29			#load $t4 with 29
			
			mult $t0,$t3			#multiply 115*exam1 
			mflo $t0			
			sra $t0,$t0,9			#divide $t3 by 512
			
			sll $t1,$t1,3			#multiply 8*exam2
			div $t1,$t4			#divide $t1 by 29
			mflo $t1
			
			sra $t2,$t2,1			#divide final exam by 2
			
			add $t2,$t2,$t1			#add final exam and exam 2
			add $t2,$t2,$t0			#add contents of $t2 to exam 1
			
			li $v0, 4
			la $a0, average			#print average label
			syscall
			
			li $v0, 1
			move $a0, $t2			#print average
			syscall
			
			li $v0, 10			#exit
			syscall
			
			
			
			