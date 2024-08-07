package database;

public class Database {
    static {
        System.loadLibrary("database");
    }
	public native void init();
	public native String execute(String s);
	public native String printTable();
	public native String save_sql(String path);
	public native String save(String path);
	public native String load(String path);
	public native void close();
	public native String tableNames();
}
