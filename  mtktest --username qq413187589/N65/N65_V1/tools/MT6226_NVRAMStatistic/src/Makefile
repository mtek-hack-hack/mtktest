include ../include/custom_include.txt
include ../include/custom_option.txt
 

NVM_OBJS = \
nvram_cust_pack.o \
nvram_common_config.o \
nvram_data_items.o \
nvram_user_config.o \
nvram_auto_gen.o

QUOTA_OBJS = \
fs_quota_entry_dump.o


NVM_OPTION =  -D "NVRAM_AUTO_GEN"
NVM_INC = -I "../include"

QUOTA_OPTION =  -D "BUILD_TIME_CHECK_GEN" -D "GEN_FOR_PC"
QUOTA_INC = -I "../../../custom/common/"

.SUFFIXES: .o .cpp .c .txt
nvram_data_items.o: ../../../nvram/src/nvram_data_items.c
	echo Compiling $< & \
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -g -w -c $< -o ../debug/$@

nvram_common_config.o: ../../../custom/common/${MMI_FOLDER}/nvram_common_config.c
	echo Compiling $< & \
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -g -w -c $< -o ../debug/$@

nvram_user_config.o: ../../../custom/app/${CUSTOM_FOLDER}/nvram_user_config.c
	echo Compiling $< & \
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -g -w -c $< -o ../debug/$@

nvram_cust_pack.o: ../../../custom/app/${CUSTOM_FOLDER}/nvram_cust_pack.c
	echo Compiling $< & \
	gcc ${CUSTOM_OPTION} $(NVM_OPTION) ${CUSTOM_INC} $(NVM_INC) -g -w -c $< -o ../debug/$@

nvram_auto_gen.o: nvram_auto_gen.c
	echo Compiling $< & \
	gcc ${CUSTOM_OPTION} ${CUSTOM_INC} $(NVM_OPTION) $(NVM_INC) -g -w -c $< -o ../debug/$@

nvram_auto_gen.exe: $(NVM_OBJS)
	echo Linking $< & \
	gcc -g -o ../debug/nvram_auto_gen ../debug/n*.o

fs_quota_entry_dump.o: fs_quota_entry_dump.c
	echo Compiling $< & \
	gcc ${CUSTOM_OPTION} ${CUSTOM_INC} ${QUOTA_OPTION} ${QUOTA_INC} -g -w -c $< -o ../debug/$@

fs_quota_entry_dump.exe: $(QUOTA_OBJS)
	echo Linking $< & \
	gcc -g -o ../debug/fs_quota_entry_dump ../debug/fs_quota_entry_dump.o
