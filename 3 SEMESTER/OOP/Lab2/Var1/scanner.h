


typedef struct {
	int id;//унікальний ідентифікатор
	char manufacturer[127];// виготовлювач
	int year; // рік виготовлення
	char model[127];// найменування моделі
	float price;// ціна
	int x_size;// горизонтальний розмір області сканування
	int y_size;// вертикальний розмір області сканування
} SCAN_INFO;


typedef struct{
	int rec_nmb;//number of records
	SCAN_INFO *recs;//records
} RECORD_SET;



void create_db(const char* csv, const char *db);
void print_db(const char *db); 
int make_index(const char *db, const char *field_name);
void reindex(const char *db);
void del_scanner(const char *db, int id);
void add_scanner(const char *db, const char* scanner_str);
RECORD_SET* select_db(const char *db, const char *field, const char *value);
void print_rec_set(RECORD_SET *rs);
RECORD_SET * get_recs_by_index(const char *dba , char *indx_field );
