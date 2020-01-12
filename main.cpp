#include <iostream>
//#include "utils/crc/crc4/crc4.h"
#include "yanujz_core/yanujz_core.h"
#include <time.h>
using namespace std;




//template <typename T, typename D>
//struct cli_cmd : public yanujz::hashable<T, D>
//{
//    cli_cmd(){
//        bzero(name, MAX_CMD_LEN);
//    }
//    cli_cmd(const char* name, cmd_func func)
//    {
//        memcpy(this->name, name, strlen(name));
//        this->execute = func;
//    }
//    const char* getKey(){
//        return name;
//    }
//    cmd_func getValue(){
//        return execute;
//    }
//
//    char name[MAX_CMD_LEN] = {0};
//    cmd_func execute = nullptr;
//};




int ls(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("ls called\n");
    return 0;
}

int rm(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("rm called\n");
    return 0;
}

int mkdir(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("mkdir called\n");
    return 0;
}

int pwd(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("pwd called\n");
    return 0;
}

int cd(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("cd called\n");
    return 0;
}

int reboot(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("reboot called\n");
    return 0;
}

int ifconfig(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("ifconfig called\n");
    return 0;
}

int cat(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("cat called\n");
    return 0;
}

int tac(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("tac called\n");
    return 0;
}

int nano(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("nano called\n");
    return 0;
}

int dump_log(int c, char** v)
{
    UNUSED(c);
    UNUSED(v);
    printf("dump_log called\n");
    return 0;
}

cmd_t cmds[] = {
    {"ls",          ls},
    {"rm",          rm},
    {"pwd",         pwd},
    {"cd",          cd},
    {"mkdir",       mkdir},
    {"reboot",      reboot},
    {"ifconfig",    ifconfig},
    {"cat",         cat},
    {"tac",         tac},
    {"nano",        nano},
    // Machine cmds
    {"dump_log",    dump_log}
};




int main()
{
    yanujz::stack<const char*, 16> stack;
    stack.push("ciao");
    stack.push("pippo");

    printf("popped: %s\n", stack.pop());
    printf("popped: %s\n", stack.pop());

    printf("end\n");
    return 0;

    CmdTable<8> table;

    for (uint i = 0; i < SIZE_OF_ARRAY(cmds); ++i) {
        cmd_table::err ret = table.add(cmds[i]);
        if(cmd_table::err::ERR_OK != ret){
            printf("error %d\n", ret);
        }
    }
    char str[64];
    while (1) {

        //gets(str);
        fgets(str, 64, stdin);
        printf("input: %s\n", str);

        cli_tokens_t tokens = cli_tokenizer_str2argv(str);

        for (int i = 0; i < tokens.argc; ++i) {
            printf("argv[%d]: %s\n", i, tokens.argv[i]);
        }

        clock_t t;
        t = clock();
        cmd_func func = table.get(tokens.argv[0]);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

        printf("table.get() took %f seconds to execute \n", time_taken);


        if(func){
            func(0, nullptr);
        }
        else {
            printf("cmd not found\n");
        }
    }

    //((cmd_func)jump_table[coord.y][coord.x])(0, nullptr);


    //cli_cmd<const char*, cmd_func> cmd("ls", ls);
    //yanujz::hashable<const char*, cmd_func>* hashable = &cmd;
    //((cmd_func)hashable->getValue())(0, nullptr);

    //yanujz::hashmap<const char*,
    //        yanujz::hashable<const char*, cli_cmd>, 32> map;

    // map.put("ls", strlen("ls"), );

    //map.get("reboot", strlen("reboot"))->value.execute(0, nullptr);

    //yanujz::hashmap<const char*, cli_cmd, 32> map;
    //printf("size %lu\n", SIZE_OF_ARRAY(cmds) );
    //{
    //    for(uint i = 0; i < SIZE_OF_ARRAY(cmds); ++i)
    //    {
    //        map.put(cmds[i].name, strlen(cmds[i].name),
    //                cli_cmd(cmds[i].name, cmds[i].func));
    //    }
    //}
    //map.get("mkdir", strlen("mkdir"))->execute(0, nullptr);
    //map.get("ls", strlen("ls"))->execute(0, nullptr);
    //map.get("reboot", strlen("reboot"))->execute(0, nullptr);
    //cli_cmd* asd = map.get("reboot", strlen("reboot"));


    return 0;
}
