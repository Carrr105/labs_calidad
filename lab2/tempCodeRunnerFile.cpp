      empty = bc.CountEmptylines();
      comm = cc.CountCommlines();
      total = cc.getTotal();
      code = total-comm-empty;
      files.push_back(FileCount(name, code, cc.getiCount(), cc.getbCount(),
       cc.getdCount(), cc.getmCount(), cc.getaCount(code)));