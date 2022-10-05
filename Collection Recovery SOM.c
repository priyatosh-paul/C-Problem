/*
 * Sample showing how to do a simple SCP transfer.
 */
#include <stdio.h>
#include <string.h>

#include <curl/curl.h>

#include <netinet/in.h>
#include <netinet/ip.h> 
#include <libssh2.h>

#ifdef HAVE_WINSOCK2_H
# include <winsock2.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif
#ifdef HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif
# ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_ARPA_INET_H
# include <arpa/inet.h>
#endif
#ifdef HAVE_SYS_TIME_H
# include <sys/time.h>
#endif

#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
//#include "/home/vaibhav/Downloads/qt-everywhere-opensource-src-4.7.3/src/3rdparty/sqlite/sqlite3.h"
#include <sqlite3.h>
#include <time.h>
#define DB_ADDR "/var/www/html/adminer/up_chi_file.db"
#define OLD_FILENAME_PATH DB_ADDR
#define NEW_FILE_PATH "/var/www/html/adminer/"

sqlite3 *db;
char The_machineno[11] = {0};
char delete_filename[100] = {0};
int DbInterface_Create_Database(char* DB_dir);
int get_waybill_details();
int DbInterface_Open_Database(char* DB_dir);
int DbInterface_Close_Database();

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  char remove_command[100] = {0};
  
//  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
//  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
//  if(mem->memory == NULL) {
    /* out of memory! */ 
//    printf("not enough memory (realloc returned NULL)\n");
//    return 0;
//  }
 
//  memcpy(&(mem->memory[mem->size]), contents, realsize);
  if(strstr(contents,"Sorry") == NULL)
  {
     	strcpy(remove_command,"rm -f ");
	strcat(remove_command,delete_filename);
	system(remove_command);
	return 1;
  }
  else
  {
	
	return 0;
  }
//  mem->size += realsize;
//  mem->memory[mem->size] = 0;
 

}


int file_upload(char *file_name_tosend)
{
  CURL *curl;
  CURLcode res;

  struct curl_httppost *formpost=NULL;
  struct curl_httppost *lastptr=NULL;
  struct curl_slist *headerlist=NULL;
  static const char buf[] = "Expect:";

  curl_global_init(CURL_GLOBAL_ALL);

  /* Fill in the file upload field */
  //curl_formadd(&formpost,
  //             &lastptr,
  //             CURLFORM_COPYNAME, "file",
  //             CURLFORM_FILE, "/root/ALM_0000037391.db",
  //             CURLFORM_END);

  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "file",
               CURLFORM_FILE, file_name_tosend,
               CURLFORM_END);

  /* Fill in the filename field */
  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "filename",
               CURLFORM_COPYCONTENTS, file_name_tosend,
               CURLFORM_END);


  /* Fill in the submit field too, even if this is rarely needed */
//  curl_formadd(&formpost,
//               &lastptr,
//               CURLFORM_COPYNAME, "submit",
//               CURLFORM_COPYCONTENTS, "send",
//               CURLFORM_END);

  curl = curl_easy_init();
  /* initialize custom header list (stating that Expect: 100-continue is not
     wanted */
  headerlist = curl_slist_append(headerlist, buf);
  if(curl) {
    /* what URL that receives this POST */
//    curl_easy_setopt(curl, CURLOPT_URL, "http://10.20.41.151/test/restore_file.php");
 curl_easy_setopt(curl, CURLOPT_URL, "http://180.92.171.140/adminer/restore_file.php");
 //   if ( (argc == 2) && (!strcmp(argv[1], "noexpectheader")) )
      /* only disable 100-continue header if explicitly requested */
 //     curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);

    /* then cleanup the formpost chain */
    curl_formfree(formpost);
    /* free slist */
    curl_slist_free_all (headerlist);
  }
  return 0;
}

static int waitsocket(int socket_fd, LIBSSH2_SESSION *session)
{
    struct timeval timeout;
    int rc;
    fd_set fd;
    fd_set *writefd = NULL;
    fd_set *readfd = NULL;
    int dir;
 
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
 
    FD_ZERO(&fd);
 
    FD_SET(socket_fd, &fd);
 
    /* now make sure we wait in the correct direction */ 
    dir = libssh2_session_block_directions(session);

 
    if(dir & LIBSSH2_SESSION_BLOCK_INBOUND)
        readfd = &fd;
 
    if(dir & LIBSSH2_SESSION_BLOCK_OUTBOUND)
        writefd = &fd;
 
    rc = select(socket_fd + 1, readfd, writefd, NULL, &timeout);
 
    return rc;
}


int trim_string(char *the_string)
{
     int i;
     for(i = 0;(i<20)&&(the_string[i]!=0x00);i++)
     {
	if(the_string[i] == ' ')
	{
		the_string[i] = 0x00;
	}
     }
}
int get_waybill_details()
{
	int rc,i,ncols, rowCnt=0;
	char *val =NULL;
	char sql[]= "select * from waybill";
	sqlite3_stmt *stmt;
	char result[34][100]={{'\0'}};
	char new_file_name[100] = {0};
	char the_date_time[200] = {0};
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);


	
	DbInterface_Create_Database(DB_ADDR);
	if(DbInterface_Open_Database(DB_ADDR))
	{
		rc = sqlite3_prepare_v2(db, sql ,-1, &stmt, 0);
		if(rc)
		{
			
			DbInterface_Close_Database();
			return -1;
		}
		//printf("Selecting data from DB success %d \n",rc);

		ncols = sqlite3_column_count(stmt);
		
		while(1)
		{
			rc = sqlite3_step(stmt);
			if(rc == SQLITE_ROW)
			{
				for (i=0;i < ncols; i++)
				{
					val = ( char*)sqlite3_column_text(stmt,i);
					if(val!=NULL)
					{
						strcpy(result[i],val);
						//printf("%s = %s\r",sqlite3_column_name(stmt,i),val);
					}
					else
					{
						printf("NULL value here\n");
					}
				}
			}
			else if(rc == SQLITE_DONE)
			{
				//printf("All rows fetched\n");
				strcpy(new_file_name,NEW_FILE_PATH);
				trim_string(result[9]);
				strcat(new_file_name,result[9]);
				strcat(new_file_name,"_");
				strcat(new_file_name,result[0]);
				strcat(new_file_name,".db");
				sqlite3_finalize(stmt);
				//printf("\n\n%s\n\n",new_file_name);
				if(strcmp(new_file_name,"/var/www/html/adminer/_.db") == 0)
				{
					printf("Machine No:%s\n",The_machineno);					
					strcpy(new_file_name,NEW_FILE_PATH);
					strncat(new_file_name,The_machineno,11);
					strcat(new_file_name,"_");
					sprintf(the_date_time,"%d%d%d%d%d%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min,tm.tm_sec);

					strcat(new_file_name,the_date_time);
					strcat(new_file_name,".db");
				}
				rename(OLD_FILENAME_PATH,new_file_name);
				memset(delete_filename,0,sizeof(delete_filename));
				strcpy(delete_filename,new_file_name);
				DbInterface_Close_Database();
				file_upload(new_file_name);
				val = NULL;
				break;
			}
			else
			{
				printf("Some error encountered\n");
				DbInterface_Close_Database();
				return -1;
			}
		}
	}
	else
	{
		DbInterface_Close_Database();
		return 0;
	}

	

	return 0;
}


int DbInterface_Open_Database(char* DB_dir)
{
	int rc = 0,ret=0;
	sqlite3 *local_db=NULL;
	int local_trans_flag=0;

	//printf("*********In DbInterface_Open_Database*********\n");

	
			rc = sqlite3_open(DB_dir , &local_db);                                                   //open cardbin.db  database file
			//			counter++;
			//			printf("counter++ %d", counter);
			if( rc )                                                                                                //operation fail
			{
				printf("Can't open database: %s \t rc:%d\n" , sqlite3_errmsg(local_db),rc);
				sqlite3_close(local_db);                                                                        //close database file
				local_db = NULL;
				//					ret = pthread_mutex_unlock(&db_mutex);
				//					printf("open db mutex unlock ....ret = %d",ret);
				return 0;//SDK_SQL_ERR;
			}
			else
			{
				
				
					
				
				//printf("Open database success: %s\n" , sqlite3_errmsg(local_db));
				//printf("local_db=%ld    db=%ld\n",local_db,db);
				return 1;

			}
		
	
	return 0;
}


/********************************************************************************
 *  Function Name:  DbInterface_Close_Database
 *  Description:
 *                  Close the database
 *
 *  Parameters: Db flag (main/thread)	   RETURN VALUE    : 1
 *
 *********************************************************************************/
int DbInterface_Close_Database()
{
	int ret=0;
	sqlite3 *local_db=NULL;
	
	
	sqlite3_close(local_db);    //close database file
			


	return 1;
}

int DbInterface_Create_Database(char* DB_dir)
{
	int rc = 0,ret=0;
	
	
	rc = sqlite3_open(DB_dir , &db);                                                   //open cardbin.db  database file
	if( rc )                                                                                                //operation fail
	{
		
		sqlite3_close(db);                                                                        //close database file
		db = NULL;
		
		return 0; //SDK_SQL_ERR;
	}
	else
	{
		
		DbInterface_Close_Database();
	}
	return 1; //SDK_OK;
}



int main(int argc, char *argv[])
{
    unsigned long hostaddr;
    float percentage=0;
    FILE *write_fp = NULL;
    int sock, i, auth_pw = 1;
    struct sockaddr_in sin;
    const char *fingerprint;
    LIBSSH2_SESSION *session;
    LIBSSH2_CHANNEL *channel;
    const char *username="root";
//    const char *password="1234";
    const char *password="5xam5Tri2015";
    const char *scppath="/root/Application/app/upsrtcdb.db";
    struct stat fileinfo;
    int rc;
    off_t got=0;
    

#ifdef WIN32
    WSADATA wsadata;
    int err;

    err = WSAStartup(MAKEWORD(2,0), &wsadata);
    if (err != 0) {
        fprintf(stderr, "WSAStartup failed with error: %d\n", err);
        return 1;
    }
#endif

    if (argc > 1) {
        hostaddr = inet_addr("192.168.1.98");// inet_addr(argv[1]);
    } else {
        hostaddr = htonl(0x7F000001);
    }
    if (argc > 2) {
        username = argv[2];
    }
    if (argc > 3) {
        password = argv[3];
    }
    if (argc > 4) {
        scppath = argv[4];
    }
    hostaddr = inet_addr("192.168.1.98");
    rc = libssh2_init (0);
    if (rc != 0) {
        fprintf (stderr, "libssh2 initialization failed (%d)\n", rc);
        return 1;
    }

    /* Ultra basic "connect to port 22 on localhost"
     * Your code is responsible for creating the socket establishing the
     * connection
     */
    sock = socket(AF_INET, SOCK_STREAM, 0);

    sin.sin_family = AF_INET;
    sin.sin_port = htons(22);
    sin.sin_addr.s_addr = hostaddr;
    if (connect(sock, (struct sockaddr*)(&sin),
            sizeof(struct sockaddr_in)) != 0) {
        fprintf(stderr, "failed to connect!\n");
        return -1;
    }

    /* Create a session instance
     */
    session = libssh2_session_init();
    if(!session)
        return -1;

    /* ... start it up. This will trade welcome banners, exchange keys,
     * and setup crypto, compression, and MAC layers
     */
    rc = libssh2_session_handshake(session, sock);
    if(rc) {
        fprintf(stderr, "Failure establishing SSH session: %d\n", rc);
        return -1;
    }

    /* At this point we havn't yet authenticated.  The first thing to do
     * is check the hostkey's fingerprint against our known hosts Your app
     * may have it hard coded, may go to a file, may present it to the
     * user, that's your call
     */
    fingerprint = libssh2_hostkey_hash(session, LIBSSH2_HOSTKEY_HASH_SHA1);
    fprintf(stderr, "Fingerprint: ");
    for(i = 0; i < 20; i++) {
        fprintf(stderr, "%02X ", (unsigned char)fingerprint[i]);
    }
    fprintf(stderr, "\n");

    if (auth_pw) {
        /* We could authenticate via password */
        if (libssh2_userauth_password(session, username, password)) {
            fprintf(stderr, "Authentication by password failed.\n");
            goto shutdown;
        }
    } else {
        /* Or by public key */
        if (libssh2_userauth_publickey_fromfile(session, username,
                            "/home/username/.ssh/id_rsa.pub",
                            "/home/username/.ssh/id_rsa",
                            password)) {
            fprintf(stderr, "\tAuthentication by public key failed\n");
            goto shutdown;
        }
    }

    /* Request a file via SCP */
    //printf("\n\nPlease Wait , Extracting File...\n\n");
    channel = libssh2_scp_recv(session, scppath, &fileinfo);

    if (!channel) {
        fprintf(stderr, "Unable to open a session: %d\n",
                libssh2_session_last_errno(session));
        goto shutdown;
    }
    printf("\n\n");
    write_fp = fopen(OLD_FILENAME_PATH,"wb");
    while(got < fileinfo.st_size) {
        char mem[1024];
        int amount=sizeof(mem);

        
	if((fileinfo.st_size -got) < amount) {
            amount = fileinfo.st_size -got;
        }

        rc = libssh2_channel_read(channel, mem, amount);
        if(rc > 0) {
	    fwrite(mem,sizeof(char),rc,write_fp);
	    //write(1, mem, rc);
        }
        else if(rc < 0) {
            fprintf(stderr, "libssh2_channel_read() failed: %d\n", rc);
            break;
        }
        got += rc;
	percentage = ((float)got/(float)fileinfo.st_size)*100.00;
	
//	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	printf("Please Wait , Extracting File...%d\%\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",(int)percentage);
	fflush(stdout);
	
    }
    printf("Please Wait , Extracting File...%d\%\n\n",100);
	fflush(stdout);
    libssh2_channel_free(channel);
    while( (channel = libssh2_channel_open_session(session)) == NULL &&

		   libssh2_session_last_error(session,NULL,NULL,0) ==

		   LIBSSH2_ERROR_EAGAIN )
	    {
		waitsocket(sock, session);
	    }
	    if( channel == NULL )
	    {
		fprintf(stderr,"Error\n");
	       return 1;
	    }

	char read_buffer[1024];
	 while( (rc = libssh2_channel_exec(channel, "/root/etim_no R")) ==

           LIBSSH2_ERROR_EAGAIN )
	    {
		waitsocket(sock, session);
	    }
	//rc = libssh2_channel_write(channel,"./root/etim_no R",strlen("./root/etim_no R"));
	if(rc == 0) {
	    
	    rc = libssh2_channel_read(channel,read_buffer,sizeof(read_buffer));
	    if(rc>0)
	    {
		   strncpy(The_machineno,read_buffer,10);
	    }
	    else
		    printf("No response\n");
	    //write(1, mem, rc);
        }
        else if(rc < 0) {
	    printf("%s","NO RESPONSE");
            fprintf(stderr, "libssh2_channel_read() failed: %d\n", rc);

        }

	
    fclose(write_fp);
    libssh2_channel_free(channel);
    get_waybill_details();
    channel = NULL;

 shutdown:

    libssh2_session_disconnect(session, "Normal Shutdown, Thank you for playing");
    libssh2_session_free(session);

#ifdef WIN32
    closesocket(sock);
#else
    close(sock);
#endif
    fprintf(stderr, "all done\n");

    libssh2_exit();

    return 0;
}
