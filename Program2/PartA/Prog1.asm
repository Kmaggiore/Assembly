"#Kendra Maggiore, CS 2318-253, Assignment 2 Part 1 Program A"					
	.data				
hello:	".asciiz ""Hello"""				
eimPrompt:	".asciiz ""Enter integer: """				
ieiLab:	".asciiz ""Integer entered is: """				
eynPrompt:	".asciiz ""Enter name: """				
yniLab:	".asciiz ""Your name is: """				
name:	.space 26	#upto 25 char + '\0'			
eygPrompt:	".asciiz ""Enter gender: """				
ygiLab:	".asciiz ""Your gender is: """				
					
	.text				
	.globl main				
main:					
	"li $v0, 4"				
	"la $a0, hello "	# prints hello			
	syscall				
					
	"li $v0, 11"				
	"li $a0, '\n'"	#new line			
	syscall				
					
	"li $v0, 4"				
	"la $a0, eimPrompt"	#prompts for int			
	syscall				
					
	"li $v0, 5"	#reads int			
	syscall				
					
	"move $t0, $v0"	#move int to temp register			
					
	"li $v0, 4"				
	"la $a0, ieiLab"	#prints label for int			
	syscall				
					
	"li $v0, 1"				
	"move $a0,$t0"	#prints int			
	syscall				
					
	"li $v0, 11"				
	"li $a0, '\n'"	#new line			
	syscall				
					
	"li $v0, 4"				
	"la $a0, eynPrompt"	#Prompts for name			
	syscall				
					
	"la $a0, name"				
	"li $a1, 26"	#reads name string			
	"li $v0, 8"				
	syscall				
					
	"li $v0, 4"				
	"la $a0, yniLab"	#prints label for name			
	syscall				
					
	"la $a0, name"				
	"li $v0, 4"	#prints name			
	syscall				
					
	"li $v0, 11"				
	"li $a0, '\n'"	#new line			
	syscall				
					
	"li $v0, 4"				
	"la $a0, eygPrompt"	#Prompts for gender			
	syscall				
					
	"li $v0, 12"	# reads char			
	syscall				
					
	"move $t0, $v0"	#move char to temp register			
					
	"li $v0, 4"				
	"la $a0, ygiLab"	#prints label for gender			
	syscall				
					
	"li $v0, 11"				
	"move $a0, $t0"	#prints char			
	syscall				
					
	"li $v0, 10"				
	syscall				
