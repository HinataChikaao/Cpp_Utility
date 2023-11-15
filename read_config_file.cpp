#include <iostream>
#include <fstream>
#include <list>

/* category name topics */
#define ERROR   ("[error]")
#define DATE    ("[date]")
#define TIME    ("[time]")
#define APP     ("[app]")
#define SERVER  ("[server]")

int main() {

    /* the name of each category is shown as a number */
    enum {
        e_error = 0, e_date = 1, e_time = 2, e_app = 3, e_server = 4, e_end = 5
    };

    /* array of category names */
    const std::string keyword_type[] = {ERROR, DATE, TIME, APP, SERVER};

    /* save the state for each of the categories */
    int state{-1};

    /* use as a enum navigator */
    int enum_now;

    /* the text file name that keeps the category names */
    const char *file_name = "config.dat";

    /* contains the text of each line */
    std::string read_line{};

    /* contains the result of trim read_line variable */
    std::string trim{};

    /* contains error keyword category */
    std::list<std::string> error_list{};

    /* contains date keyword category */
    std::list<std::string> date_list{};

    /* contains time keyword category */
    std::list<std::string> time_list{};

    /* contains app keyword category */
    std::list<std::string> app_list{};

    /* contains server keyword category */
    std::list<std::string> server_list{};

    /* contains all lists keywords categories to navigate in the loop section */
    std::list<std::string> all_lists[]{error_list, date_list, time_list, app_list, server_list};

    /* file object setting */
    std::ios_base::openmode read_mode{std::ios::in};
    std::ifstream read_file{};

    read_file.open(file_name, read_mode);
    if (!read_file.is_open()) {
        perror("error in opening file");
        exit(EXIT_FAILURE);
    }

    /* start reading keywords in the loop */
    while (std::getline(read_file, read_line)) {

        /* checks read_line variable if it starts with '#' or read_line length be zero */
        if (read_line.length() == 0 || read_line.starts_with('#')) continue;

        /* trim the line that has been read and save it in trim variable */
        size_t pos1 = read_line.find_first_not_of('\n');
        std::string left_pad = read_line.substr(pos1);
        size_t pos2 = left_pad.find_last_not_of('\n');
        trim = left_pad.substr(0, pos2 + 1);

        /* it checks the line which has been read if comprises category name.
         * relevant the result it set the state category. if no category name find,
         * state stay with it stay with default value (-1) */
        for (enum_now = e_error; enum_now < e_end;) {
            if (!(std::equal(trim.begin(), trim.end(), std::begin(keyword_type[enum_now])))) {
                enum_now++;
                continue;
            } else {
                state = enum_now;
                break;
            }
        }

        /* assign the content of the content of the trim to relevant category list */
        switch (state) {
            case e_error: {
                all_lists[e_error].emplace_back(trim);
                break;
            }
            case e_date: {
                all_lists[e_date].emplace_back(trim);
                break;
            }
            case e_time: {
                all_lists[e_time].emplace_back(trim);
                break;
            }
            case e_app: {
                all_lists[e_app].emplace_back(trim);
                break;
            }
            case e_server: {
                all_lists[e_server].emplace_back(trim);
                break;
            }
            default: {
                std::cout << "current mode is: " << trim << '\n';
            }
        }

        /* clear the content of the trim and read_line variables */
        trim.clear();
        read_line.clear();
    }


    std::cout << '\n' << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';
    for (std::list<std::string> &lst: all_lists) {
        for (std::string &str: lst) {
            std::cout << str << '\n';
        }
        std::cout << '\n' << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';
    }

    read_file.close();

    std::cout << "\nThe End ..." << std::endl;
    return EXIT_SUCCESS;
}
