#include "database_Database.h"
#include "Database.h"

Database *db;
JNIEXPORT void JNICALL Java_database_Database_init(JNIEnv *, jobject) {
  if (db)
    delete db;
  db = new Database();
}

JNIEXPORT jstring JNICALL Java_database_Database_execute(JNIEnv *env, jobject,
                                                         jstring str) {
  return env->NewStringUTF(
      db->execute(env->GetStringUTFChars(str, NULL)).c_str());
}

JNIEXPORT jstring JNICALL Java_database_Database_printTable(JNIEnv *env,
                                                            jobject) {
  return env->NewStringUTF(db->printTable().c_str());
}

JNIEXPORT jstring JNICALL Java_database_Database_save_1sql(JNIEnv *env, jobject,
                                                           jstring str) {
  return env->NewStringUTF(
      db->save_sql(env->GetStringUTFChars(str, NULL)).c_str());
}

JNIEXPORT jstring JNICALL Java_database_Database_save(JNIEnv *env, jobject,
                                                      jstring str) {
  return env->NewStringUTF(db->save(env->GetStringUTFChars(str, NULL)).c_str());
}

JNIEXPORT jstring JNICALL Java_database_Database_load(JNIEnv *env, jobject,
                                                      jstring str) {
  return env->NewStringUTF(db->load(env->GetStringUTFChars(str, NULL)).c_str());
}

JNIEXPORT void JNICALL Java_database_Database_close(JNIEnv *, jobject) {
  if (db)
    delete db;
  db = nullptr;
}

JNIEXPORT jstring JNICALL Java_database_Database_tableNames(JNIEnv *env,
                                                            jobject) {
  return env->NewStringUTF(db->tableNames().c_str());
}