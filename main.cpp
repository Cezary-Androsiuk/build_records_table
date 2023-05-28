#include <cstdio>
#include <string>
#include <vector>

// #include <sys/ioctl.h>
// #include <unistd.h>

// g++ main.cpp -o main && ./main

std::vector<std::vector<std::string>> getTableData();
void printTable(std::vector<std::vector<std::string>>);

int main(int argc, char** argv){
    printTable(getTableData());
}


void printTable(std::vector<std::vector<std::string>> vvs){
    int maxColumnsCount = vvs[0].size();
    for(std::vector<std::string> vs : vvs){
        int singleCC = vs.size();
        if(singleCC < maxColumnsCount){
            maxColumnsCount = singleCC;
            printf("NOT ALL COLUMNS WILL BE PRINTED!\n");
        }
    }
    // assume that all rows have equal count of strings
    // but to avoid error we try to find the shortest one

    std::vector<int> maxWidth;
    for(int i=0; i<maxColumnsCount; i++){
        int maxSingleRowWidth = 0;
        for(std::vector<std::string> vs : vvs){
            int singleWidth = vs[i].size();
            if(singleWidth > maxSingleRowWidth) 
                maxSingleRowWidth = singleWidth;
        }
        maxWidth.push_back(maxSingleRowWidth);
    }
    int totalWidth = 1;
    for(int i : maxWidth)
        totalWidth += i + 2 + 1;

    // struct winsize w;
    // ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    // if(w.ws_col < totalWidth){
    //     printf("NOT ENOUGHT TERMINAL SIZE!\n");
    // }

    bool namePrinted = false;

    for(std::vector<std::string> vs : vvs){
        for(int i=0; i<vs.size(); i++){
            printf("| ");
            int diff = maxWidth[i]-vs[i].size();
            for(int k=0; k<diff; k++)
                printf(" ");
            printf("%s ", vs[i].c_str());
        }
        printf("|\n");

        if(!namePrinted){
            for(int i=0; i<totalWidth; i++)
                printf("-");
            printf("\n");
            namePrinted = true;
        }
    }
}


std::vector<std::vector<std::string>> getTableData(){
    /* Data from sqlite3 class examples */
    // |id | name | surname | pesel | birth_date | phone | add_date | height | additional_info | 
    // | 1 | Cezary | Androsiuk | 123456789AB | 01-01-2002 | 48123456789 | 27-05-2023 | NULL | NO INFO | 
    // | 2 | Cezary | Androsiuk | 123456789AB | 01-01-2002 | 48123456789 | 27-05-2023 | NULL | additional text  | 
    // | 3 | Czaruś | ABCDEFXYZ | 123456789AB | 01-01-2002 | NULL | TIMESTAMP | NULL | additional text  | 
    // | 4 | Stanisław | ABCDEFXYZ | 123456789AB | 01-01-2002 | NULL | TIMESTAMP | NULL | NO INFO | 
    // | 5 | Stanisław | ABCDEFXYZ | 123456789AB | 01-01-2002 | NULL | TIMESTAMP | NULL | NO INFO |

    std::vector<std::vector<std::string>> vvs;
    std::vector<std::string> vs;
    vs.push_back( std::string("id")                 );
    vs.push_back( std::string("name")               );
    vs.push_back( std::string("surname")            );
    vs.push_back( std::string("pesel")              );
    vs.push_back( std::string("birth_date")         );
    vs.push_back( std::string("phone")              );
    vs.push_back( std::string("add_date")           );
    vs.push_back( std::string("height")             );
    vs.push_back( std::string("additional_info")    );
    vvs.push_back(std::vector<std::string>(vs));
    vs.clear();
    vs.push_back( std::string("1")                  );
    vs.push_back( std::string("Cezary")             );
    vs.push_back( std::string("Androsiuk")          );
    vs.push_back( std::string("123456789AB")        );
    vs.push_back( std::string("01-01-2002")         );
    vs.push_back( std::string("48123456789")        );
    vs.push_back( std::string("27-05-2023")         );
    vs.push_back( std::string("NULL")               );
    vs.push_back( std::string("NO INFO")            );
    vvs.push_back(std::vector<std::string>(vs));
    vs.clear();
    vs.push_back( std::string("2")                  );
    vs.push_back( std::string("Cezary")             );
    vs.push_back( std::string("Androsiuk")          );
    vs.push_back( std::string("123456789AB")        );
    vs.push_back( std::string("01-01-2002")         );
    vs.push_back( std::string("48123456789")        );
    vs.push_back( std::string("27-05-2023")         );
    vs.push_back( std::string("NULL")               );
    vs.push_back( std::string("additional text")    );
    vvs.push_back(std::vector<std::string>(vs));
    vs.clear();
    vs.push_back( std::string("3")                  );
    vs.push_back( std::string("Czarus")             );
    vs.push_back( std::string("ABCDEFXYZ")          );
    vs.push_back( std::string("123456789AB")        );
    vs.push_back( std::string("01-01-2002")         );
    vs.push_back( std::string("NULL")               );
    vs.push_back( std::string("TIMESTAMP")          );
    vs.push_back( std::string("NULL")               );
    vs.push_back( std::string("additional text")    );
    vvs.push_back(std::vector<std::string>(vs));
    vs.clear();
    vs.push_back( std::string("4")                  );
    vs.push_back( std::string("Stanislaw")          );
    vs.push_back( std::string("ABCDEFXYZ")          );
    vs.push_back( std::string("123456789AB")        );
    vs.push_back( std::string("01-01-2002")         );
    vs.push_back( std::string("NULL")               );
    vs.push_back( std::string("TIMESTAMP")          );
    vs.push_back( std::string("NULL")               );
    vs.push_back( std::string("NO INFO")            );
    vvs.push_back(std::vector<std::string>(vs));
    vs.clear();
    vs.push_back( std::string("5")                  );
    vs.push_back( std::string("Stanislaw")          );
    vs.push_back( std::string("ABCDEFXYZ")          );
    vs.push_back( std::string("123456789AB")        );
    vs.push_back( std::string("01-01-2002")         );
    vs.push_back( std::string("NULL")               );
    vs.push_back( std::string("TIMESTAMP")          );
    vs.push_back( std::string("NULL")               );
    vs.push_back( std::string("NO INFO")            );
    vvs.push_back(std::vector<std::string>(vs));
    vs.clear();
    return std::vector<std::vector<std::string>>(vvs);
}