class tokenizer{
private:
    FILE* dataFile;
    char line[1024];
    char* retval;
    const char* MOD_SEPS;
    void setFile(FILE* fp);
public:
    tokenizer();
    tokenizer(FILE* fp);
    char* getToken();
    ~tokenizer();
};