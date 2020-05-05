//
// Created by Enrico on 05/05/2020.
//

#ifndef ALGADV_HW2_PARSER_H
#define ALGADV_HW2_PARSER_H
#include <vector>
#include <fstream>
#include <sstream>

//coordinate types enum
enum class coord_type{
    cartesian,
    geo,
    none
};

//parsed data type
typedef struct Obj{
    std::string name;
    coord_type ty;
    unsigned int dim;
    std::vector<std::pair<double, double>> cities;
} Parsed_Map;

class Parser{
public:
    static Parsed_Map parse(const std::filesystem::path&);
};

Parsed_Map Parser::parse(const std::filesystem::path& f_name) {
    std::ifstream ifs (f_name, std::ifstream::in);
    std::vector<std::pair<double, double>> data_points;

    if(ifs.good()) {
        std::string d_line;
        std::string name;
        unsigned int dim;
        coord_type type;

        //get name
        std::getline(ifs, d_line);
        std::stringstream nameStr(d_line);
        nameStr.ignore(256, ':');
        nameStr >> name;

        //get dimension
        ifs.ignore(256, '\n');
        ifs.ignore(256, '\n');
        std::getline(ifs, d_line);
        std::stringstream dimStr(d_line);
        dimStr.ignore(256, ':');
        dimStr >> dim;

        //get type
        std::string strtype;
        std::getline(ifs, d_line);
        std::stringstream typeStr(d_line);
        typeStr.ignore(256, ':');
        typeStr >> strtype;
        if(strtype == "EUC_2D"){
            type = coord_type::cartesian;
        } else type = coord_type ::geo;

        //get coordinates
        ifs.ignore(256, '\n');
        ifs.ignore(256, '\n');

        unsigned int i = 0;
        while (std::getline(ifs, d_line) && i < dim) {
            std::stringstream lineStream(d_line);
            double value1;
            double value2;

            lineStream.ignore(256, ' ');
            lineStream.ignore(256, ' ');
            lineStream >> value1;
            lineStream >> value2;
            data_points.emplace_back(value1, value2);

            ++i;
        }
        ifs.close();
        return {name, type, dim, data_points};
    }else{
        return {"", coord_type::none, 0, data_points};
    }
}

#endif //ALGADV_HW2_PARSER_H
