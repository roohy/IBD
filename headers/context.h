//
// Created by Ruhollah Shemirani on 3/29/17.
//

#ifndef IBD_CONTEXT_H
#define IBD_CONTEXT_H


#include <string>
//#include <map>
#include <vector>
#include <mutex>
#include <unordered_set>


typedef uint8_t dnabit;

class MapData{
public:
    std::string chrome;
    std::string RSID;
    double gen_dist;
    unsigned position;
    MapData(std::string,std::string,double,unsigned);




};

class Context{
public:
    static const unsigned long word_count = 4294967311;
    bool map_flag;
    std::vector<MapData> map_data;
    std::vector<std::pair<unsigned long , unsigned  long> > shingle_map;
    std::vector<std::pair<unsigned long,unsigned long> > slice_idx;
    std::vector<std::pair<unsigned ,unsigned > >shingle_idx;


    unsigned
    unsigned long slice_count;
    unsigned perm_count;
    std::pair<unsigned long, unsigned long> **perm_matrix;
    unsigned shingle_size;
    unsigned bucket_count;
    unsigned bucket_size;
    double *approx_list;
    double threshold;
    unsigned minimum_match;
    unsigned minimum_interest;
    unsigned shingle_overlap;
    unsigned slice_size;
    unsigned step_size;
    double match_thresh;
    double minimum_length;
    unsigned short max_error;









    Context();
    void read_map(const char* );
    void slice_map(unsigned,unsigned);
    void prepare_for_minhash(unsigned ,unsigned, unsigned);
    void prepare_context(const char *,unsigned,unsigned ,unsigned ,unsigned ,unsigned ,unsigned ,double,double,double,
                         unsigned short);
    void approximate();
    bool same_chrom(unsigned long &i1, unsigned long &i2);
    bool is_last_slice(unsigned);
    bool is_first_slice(unsigned);
    unsigned shingles_in_slice(unsigned long, unsigned long);

};

#endif //IBD_CONTEXT_H
