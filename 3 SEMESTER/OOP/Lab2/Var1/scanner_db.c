#include "scanner.h"





int main(){
	create_db("scan.csv","scan.db");
	print_db("scan.db");	
	make_index("scan.db","manufacturer");
	reindex("scan.db");
	add_scanner("scan.db", "ASUS;AS1055;2009;99.99;210;297");
	print_db("scan.db");
	del_scanner("scan.db", 5);
	print_db("scan.db");
	RECORD_SET* rs = select_db("scan.db", "manufacturer", "ASUS");
	print_rec_set(rs);
	rs = get_recs_by_index("scan.db", "manufacturer");
	print_rec_set(rs);

	return 0;	
}
