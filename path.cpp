#include <path.hpp>
Path::Path(int pathLen, bool randomGen=false){
    _pathLen = pathLen;
    _path = new int[pathLen];
    if(randomGen){
        for(int i(0) ; i<pathLen ; i++){
            _path[i] = i;
        }
        for(int i(0) ; i<pathLen ; i++){
            j = rand()%_pathLen;
            int temp = _path[j];
            _path[j] = _path[i];
            _path[i] = temp;
        }
    }
    else{
        for(int i(0) ; i<pathLen ; i++){
            _path[i] = -1;
        }
    }
}
Path Path::crossOver2(Path path1, Path path2){
    Path newPath1 newPath2;
    std::vector<int> indexDouble1 indexDouble2;

    int l = rand()%_pathLen;
    for(int i(0) ; i<l ; i++){
        newPath1[i] = path1[i];
        newPath2[i] = path2[i]
    }
    for(int i(l) ; i<_pathLen : i++){
        newPath1[i] = Path2[i];
        newPath2[i] = Path1[i];
    }
Path Path::crossOver(Path path1, Path path2){
    Path newPath(path1._pathLen, false);
    std::vector<bool> assigned(false,path1._pathLen);
    std::vector<int> notAssigned;

    for(int i(0) ; i<path1._pathLen; i++){
        if (not(path1[i] in newPath)){
            if (not(path2[i] in newPath)){
                int r = rand()%1;
                newPath[i] = r*path1[i] + (1-r)*path2[i]
            }
            else{
                newPath[i] = path1[i]
            }
        }
        else{
            if (not(path2[i] in newPath)){
                newPath[i] = path2[i]
            }
        }
    }

    for(int i(0) ; i<_pathLen : i++){
        if (newPath[i]!=-1)
        {
            assigned[newPath[i]] = true;
        }
    }

    for(int i(0) ; i<_pathLen : i++){
        if (assigned[i])
        {
            notAssigned.push(i);
        }
    }

}


Path mutation();

void Path::evaluate(){
    _fitness = 0;
    for(int i(0) ; i<_pathLen-1 ; i++){ // Attention graph complet
        _fitness += graph[_path[i]][_path[i+1]];
    }
    _fitness += _graph[_path[0]][_path[_pathLen-1];
}

template<T>
bool in(std::vector<T> list, T x, int i){
    for(int j(0) ; j<i ; j++){
        if(x == list[j]){
            return true;
        }
    }
    return false;
}
