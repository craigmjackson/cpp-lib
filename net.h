#include <string>
using namespace std;

#ifndef NET_H
#define NET_H

string netmask_from_cidr(int cidr);
int cidr_from_netmask(string netmask);
string http_get(string url);
string http_post(string url);
string http_delete(string url);
void download_file(string url, string path);

#endif // NET_H
