typedef enum ResourceType { RT_CPU, RT_MEMORY, RT_IO } ResourceType;

typedef struct {
    double some;
    double full;
} TimeResourcePressure;

typedef struct {
    TimeResourcePressure ten;
    TimeResourcePressure sixty;
    TimeResourcePressure three_hundred;
} Pressure;

typedef struct {
    char *filename;
    char *human_name;
    unsigned int has_full;
    ResourceType type;
    Pressure thresholds;
} Resource;

typedef struct {
    Resource cpu;
    Resource memory;
    Resource io;
    unsigned int update_interval;
} Config;

#define info(format, ...) printf("INFO: " format, __VA_ARGS__)
#define warn(format, ...) fprintf(stderr, "WARN: " format, __VA_ARGS__)
#define expect(x)                                                              \
    do {                                                                       \
        if (!(x)) {                                                            \
            fprintf(stderr, "FATAL: !(%s) at %s:%s:%d\n", #x, __FILE__,        \
                    __func__, __LINE__);                                       \
            abort();                                                           \
        }                                                                      \
    } while (0)
