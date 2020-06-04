
#ifndef __CFG_OP_H__
#define __CFG_OP_H__

// 写修改配置文件
int write(const char *pfile, const char *key, const char *vlaue, int len);

// 读配置文件
int read(const char *pfile, const char *key, char *value);

#endif

