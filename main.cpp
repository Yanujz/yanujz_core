#include <iostream>
//#include "utils/crc/crc4/crc4.h"
#include "yanujz_core/yanujz_core.h"
using namespace std;


#define MAX_CMD_LEN 16
typedef int (*cmd_func)(int argc, char** argv);


class hashable {

protected:
    unsigned int uid;
};

struct cli_cmd : public hashable {
    cli_cmd(){
        bzero(name, MAX_CMD_LEN);
    }
    cli_cmd(const char* name, cmd_func func)
    {
        memcpy(this->name, name, strlen(name));
        this->execute = func;
    }

    char name[MAX_CMD_LEN] = {0};
    cmd_func execute = nullptr;
};

struct cmd_t {
    const char name[16];
    cmd_func func;
};



int ls(int argc, char** argv)
{
    printf("ls called\n");
    return 0;
}


int rm(int c, char** v){
    printf("rm called\n");
    return 0;
}
int mkdir(int argc, char** argv)
{
    printf("mkdir called\n");
    return 0;
}

int pwd(int c, char** v){
    printf("pwd called\n");
    return 0;
}

int cd(int c, char** v){
    printf("cd called\n");
    return 0;
}

cmd_t cmds[] = {
    {"ls",               ls},
    {"rm",          rm},
    {"pwd",             pwd},
    {"cd",          cd},
    {"mkdir",       mkdir},
    {"reboot",      nullptr},
    {"ifconfig", nullptr},
    {"cat",  nullptr},
    {"tac",  nullptr},
    {"nano", nullptr},
    // Machine cmds
    {"dump_log",    nullptr}
};

int main()
{

    //yanujz::list<cli_cmd> list;
    //list.push_back(cli_cmd("ls", ls));
    //list.push_back(cli_cmd("mkdir", mkdir));

    //printf("cmd name %s\n", list.get(0)->name);
    //printf("swapping\n");
    //list.swap(0, 1);
    //printf("swapped\n");
    //printf("cmd name %s\n", list.get(0)->name);

    yanujz::dl_list<cli_cmd> temp;
    // mkdir ls cd pwd rm
    temp.push_front(cli_cmd("ls", ls));
    temp.push_front(cli_cmd("mkdir", mkdir));
    temp.push_back(cli_cmd("pwd", pwd));
    temp.push_back(cli_cmd("rm", rm));
    temp.push_back(cli_cmd("cd", cd));


    temp.erase(2);
    yanujz::std_err ret = temp.swap(0, 4);
    if(yanujz::std_err::ERR_OK != ret) {
        printf("can't swap\n");
        exit(1);
    }
    cli_cmd* cmd = temp.get(0);
    if(cmd){
        cmd->execute(1, nullptr);
    }
    else {
        printf("null returned\n");
    }
    //if(list[0].isEmpty()){
    //    printf("list is empty\n");
    //}
    //list[0].push_back(cli_cmd("ls", ls));
    //list[0].push_back(cli_cmd("mkdir", mkdir));
    //list[0].push_back(cli_cmd("pippo", pippo));
    //printf("size %d\n", list[0].size());
    //cli_cmd asd = list[0][1];
    //asd.execute(0, nullptr);
    //list[0].front().execute(0, nullptr);
    //list[0].back().execute(0, nullptr);


    //for (int var = 0; var < total; ++var) {
    //
    //}

    //yanujz::hashmap<const char*, cli_cmd, 64> map;
    //map.put("ls", strlen("ls"), cli_cmd("ls", ls));
    //map.put("mkdir", strlen("mkdir"), cli_cmd("mkdir", mkdir));
    //map.put("mkdir", strlen("mkdir"), cli_cmd("mkdir", mkdir));
    //map.get("mkdir", strlen("mkdir"))->execute(0, nullptr);

    //{
    //    map.put("ls", strlen("ls"), cli_cmd("ls", ls));
    //    //map.put("ls", strlen("ls"), cli_cmd("ls", mkdir));
    //}
    //map.get("ls", strlen("ls"))->execute(0, nullptr);


    return 0;
}
