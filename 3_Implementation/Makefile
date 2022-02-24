#TargetName : Dependencies
#<TAB>commands

PROJ_NAME=Matrixoperation
SRC=src/Matrixoperation.c src/Matrixoperation.c src/unity.c

#To check if the OS is windows or linux and set the exceutable file extension and delete command accordingly
 ifdef  OS
  RM = del/q
  FixPath = $(subst /,\,$1)
  EXEC = exe
else
   ifeq ($(shell uname), Linux)
     RM = rm -rf
	 FixPath = $1
	 EXEC = out
   endif  
endif


Build : $(SRC)
	gcc $(SRC) -Iinc -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm

Run : Build
	./$(call FixPath,$(PROJ_NAME).$(EXEC))


Clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*.out)