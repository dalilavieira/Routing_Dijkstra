#define tam 11
int edges = 125;
int place[] = {255 ,255 ,255 ,70 ,75 ,82 ,33 ,45 ,20 ,5 ,43 ,255 ,255 ,255 ,60 ,66 ,87 ,58 ,48 ,27 ,14 ,55 ,255 ,255 ,36 ,49 ,56 ,92 ,22 ,35 ,86 ,30 ,65 ,255 ,255 ,23 ,44 ,97 ,96 ,7 ,95 ,91 ,81 ,74 ,255 ,2 ,9 ,100 ,99 ,98 ,94 ,93 ,3 ,17 ,25 ,255 ,11 ,32 ,31 ,18 ,4 ,90 ,88 ,0 ,38 ,12 ,255 ,19 ,47 ,52 ,59 ,1 ,76 ,83 ,69 ,51 ,57 ,255 ,15 ,53 ,63 ,68 ,67 ,89 ,79 ,71 ,62 ,46 ,255 ,29 ,42 ,39 ,72 ,78 ,85 ,84 ,61 ,34 ,10 ,255 ,255 ,28 ,41 ,40 ,73 ,80 ,8 ,50 ,37 ,24 ,255 ,13 ,16 ,26 ,54 ,64 ,255 ,6 ,77 ,21 ,255};
int e_a[] = {100 ,99 ,99 ,98 ,96 ,92 ,87 ,82 ,75 ,75 ,70 ,60 ,49 ,36 ,23 ,9 ,66 ,66 ,56 ,44 ,31 ,18 ,4 ,58 ,58 ,48 ,35 ,22 ,7 ,45 ,45 ,33 ,33 ,27 ,14 ,20 ,5 ,97 ,97 ,95 ,91 ,86 ,81 ,74 ,65 ,55 ,43 ,30 ,17 ,3 ,94 ,94 ,93 ,88 ,83 ,83 ,79 ,71 ,62 ,51 ,38 ,38 ,25 ,12 ,76 ,76 ,67 ,69 ,69 ,61 ,50 ,37 ,37 ,24 ,10 ,57 ,57 ,46 ,46 ,34 ,21 ,21 ,8 ,6 ,90 ,90 ,89 ,89 ,85 ,80 ,73 ,64 ,54 ,54 ,40 ,41 ,28 ,28 ,16 ,84 ,84 ,77 ,78 ,78 ,72 ,63 ,53 ,53 ,42 ,29 ,15 ,68 ,68 ,59 ,59 ,47 ,32 ,19 ,19 ,11 ,52 ,52 ,39 ,26 ,13};
int e_b[] = {99 ,97 ,98 ,96 ,92 ,87 ,82 ,75 ,66 ,70 ,60 ,49 ,36 ,23 ,9 ,2 ,58 ,56 ,44 ,31 ,18 ,4 ,1 ,45 ,48 ,35 ,22 ,7 ,2 ,33 ,31 ,20 ,27 ,14 ,2 ,5 ,1 ,95 ,94 ,91 ,86 ,81 ,74 ,65 ,55 ,43 ,30 ,17 ,3 ,0 ,93 ,90 ,88 ,83 ,76 ,79 ,71 ,62 ,51 ,38 ,27 ,25 ,12 ,2 ,69 ,67 ,56 ,57 ,61 ,50 ,37 ,27 ,24 ,10 ,2 ,44 ,46 ,34 ,31 ,21 ,8 ,6 ,2 ,1 ,89 ,86 ,85 ,84 ,80 ,73 ,64 ,54 ,40 ,41 ,27 ,28 ,14 ,16 ,2 ,77 ,78 ,67 ,68 ,72 ,63 ,53 ,42 ,40 ,29 ,15 ,2 ,59 ,56 ,52 ,47 ,32 ,19 ,4 ,11 ,2 ,40 ,39 ,26 ,13 ,2};