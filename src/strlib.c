#include "strlib.h"


size_t strlib_strlen (const char* str )
{
    if (str == NULL ) return SIZE_MAX ;
    int i = 0 ;
    while (str[i] != '\0' ) i ++ ;
    return i ;
}


char* strlib_strdup (const char* src )
{
    size_t i = strlib_strlen(src); 
    if (i == SIZE_MAX ) return NULL ; 
    char* copy = malloc((i+1) *sizeof(char) );
    if (copy == NULL ) return NULL ; 
    for ( int j = 0 ; j <= i ; j++)
    {
        copy[j] = src[j] ;
    }
    return copy ;
}


size_t strlib_strcpy(char* dest, size_t dest_size, const char* src)
{
    size_t src_len = strlib_strlen(src) ;
    size_t dest_len = strlib_strlen(dest) ;
    if ( src_len == SIZE_MAX || dest_len == SIZE_MAX || src_len +1 > dest_size ) return SIZE_MAX ;
    for (int i = 0 ; i < src_len +1 ; i++)
    {
        dest[i] = src[i];
    }
    return 0 ;
}


size_t strlib_strncat(char* dest, size_t dest_size, const char* src, size_t n)
{
    size_t dest_len = strlib_strlen(dest) ;
    size_t src_len = strlib_strlen(src) ;
    if ( dest_len == SIZE_MAX || src_len == SIZE_MAX || dest_len + n +1 > dest_size) return SIZE_MAX ;
    int i = 0 ;
    for ( i; i < n; i++)
    {
        dest[dest_len + i] = src[i] ;
    }
    dest[dest_len + n ] = '\0' ;
    return 0 ;
}


StrcmpResult strlib_strcmp(const char* s1, const char* s2)
{
    if ( s1 == NULL || s2 == NULL) return STRCMP_ERROR ;
    int i = 0 ;
    while (s1[i] != '\0' && s2[i] != '\0') 
    {
        if ( s1[i] > s2[i] ) return STRCMP_GREATER ;
        if ( s1[i] < s2[i] ) return STRCMP_LESS ;
        i ++ ;
    }
    if ( s1[i] == s2[i] ) return STRCMP_EQUAL ;
    if ( s1[i] == '\0' ) return STRCMP_LESS ;
    return STRCMP_GREATER ;
}


char* strlib_strtok(char* str, const char* delim)
{
    static char* ptr = NULL ;
    if ( (str == NULL && ptr == NULL ) || delim == NULL ) return NULL ;
    if ( str != NULL ) ptr = str ; 
    char* token_start = ptr;
    for (int i = 0 ; ptr [i] != '\0' ; i ++)
    {
        for ( int j = 0 ; delim[j] != '\0' ; j ++)
        {
            if (ptr [i] == delim[j])
            {
                ptr[i] = '\0' ;
                ptr = &ptr[i + 1] ;
                if (token_start[0] == '\0') return strlib_strtok(NULL , delim ) ;
                return token_start ;
            }
        }
    }
    ptr = NULL ;
    return token_start ;
}


char* strlib_trim(const char* src)
{
    if (src == NULL ) return NULL ;
    int start = 0 ; 
    int end = 0 ;
    for (int i = 0; src[i] != '\0' ; i++)
    {
        if (src[i] == ' ' || src[i] == '\t' || src[i] == '\n' || src[i] == '\r')
        {
            if ( i == start ) { start++ ; end++ ;}
            continue;
        }
        end = i ;
    }
    char* trimmed_str = malloc((end-start + 2)*sizeof(char));
    if (trimmed_str == NULL ) return NULL ;
    for (int i = 0 ;i < end-start+1 ; i++ )
    {
        trimmed_str[i] = src[start+i] ;
    } 
    trimmed_str[end-start+1] = '\0' ;
    return trimmed_str ;
}


size_t strlib_find(const char* haystack, const char* needle)
{
    if (haystack == NULL || needle == NULL) return SIZE_MAX ;

    if (needle[0] == '\0') return 0 ;
    if (haystack[0] == '\0') return SIZE_MAX ;
    size_t index = 0 ;
    size_t t = 0 ;
    while ( haystack[index] != '\0' )
    {
        if (haystack[index + t ] == needle[t]) 
        {
            if (needle[ t ] == '\0') break;
            t ++ ;
            continue;
        }
        if (needle[ t ] == '\0') break;
        index ++ ;
        t = 0 ;
    }
    if ( t < strlib_strlen(needle) ) return SIZE_MAX ;
    return index ;
}


Bool strlib_contains(const char* haystack, const char* needle)
{
    size_t result = strlib_find(haystack , needle); 
    if (result == SIZE_MAX) return FALSE ;
    return TRUE ;
}


char* strlib_substr(const char* src, size_t start, size_t n)
{
    size_t src_len = strlib_strlen(src) ;
    if ( src_len == SIZE_MAX) return NULL ;
    if ( src_len <= start ) return NULL ;
    size_t substr_len = (src_len - start > n ) ? n+1 : src_len - start + 1 ;
    char* substr = malloc(substr_len * sizeof(char)) ;
    if ( substr == NULL) return NULL ;
    for (size_t i = 0; i < substr_len; i++)
    {
        substr[i] = src [start + i] ;
    }
    substr[substr_len-1] = '\0' ;
    return substr ;
}


char* strlib_to_upper(const char* src)
{
    if (src == NULL ) return NULL ;
    if (src[0] == '\0' )
    {
        char* uppered = malloc (sizeof(char) * 1) ;
        uppered[0] = '\0' ;
        return uppered ;
    }
    size_t uppered_size = strlib_strlen(src) +1 ;
    char* uppered = malloc(uppered_size * sizeof(char)) ;
    for (int i = 0 ; src[i] != '\0' ; i++)
    {
        uppered[i] = src[i] ;
        if ( uppered[i] >= 'a' && uppered[i] <= 'z')
        {
            uppered[i] = uppered[i] - 'a' + 'A' ;
        }
    }
    uppered[uppered_size-1] = '\0' ;
    return uppered ;
}


char** strlib_split(const char* src, char delim, size_t* count)
{
    if( src == NULL || count == NULL ) return NULL ;
    if (src[0] == '\0') 
    {
        *count = 0 ; 
        char** tokens = malloc(1 * sizeof(char*)) ;
        if (tokens == NULL) return NULL ;
        tokens[0] = malloc( 1 * sizeof(char)) ;
        if( tokens[0] == NULL ) {free(tokens) ; return NULL ;}
        tokens[0][0] = '\0' ;
        return tokens ;
    }
    *count = 1 ;
    for ( size_t i = 0 ; src[i] != '\0' ; i++)
    {
        if (src[i] == delim ) (*count)++ ;
    }
    char** tokens = malloc(*count * sizeof(char*)) ;
    if ( tokens == NULL ) return NULL ;
    size_t start = 0 ; 
    size_t end = 0;
    size_t t_n = 0 ;
    for (size_t i = 0 ;; i++)
    {
        if ( src[i] == '\0' || src[i] == delim )
        {
            end = i ;
            char* new_token = malloc((end - start +1)*sizeof(char));
            if (new_token == NULL )
            {
                for (size_t k = 0; k < t_n; k++) {free(tokens[k]) ;}
                free(tokens);
                return NULL ;
            }
            size_t j ;
            for ( j = 0 ; j < end - start ; j ++)
            {
                new_token[j] = src[start + j ] ;
            }
            new_token[end - start ] = '\0';
            tokens[t_n] = new_token ;
            t_n ++ ;
            end = start = i+1 ;
        }
        if (src[i] == '\0') break;
    }
    return tokens ;
}



