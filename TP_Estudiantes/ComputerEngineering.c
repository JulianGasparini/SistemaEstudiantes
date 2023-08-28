#include "StudentsSystem.c"

Career* initialize_computer_data(){
    Career *nuevaCarrera = create_career("Ciencia de Datos");

    add_subject(nuevaCarrera, "Introduccion a la Programacion");

    add_subject(nuevaCarrera, "Matematica Discreta");

    add_subject(nuevaCarrera, "Estadistica");
    char correlatives_Estadistica[] = {2};
    add_correlative_array_to_subject(nuevaCarrera, "Estadistica", correlatives_Estadistica, 1);

    add_subject(nuevaCarrera, "Algoritmos y Estructuras de Datos");
    char correlatives_AlgoritmosEstructuras[] = {1};
    add_correlative_array_to_subject(nuevaCarrera, "Algoritmos y Estructuras de Datos", correlatives_AlgoritmosEstructuras, 1);

    add_subject(nuevaCarrera, "Bases de Datos");
    char correlatives_BasesDatos[] = {3, 4};
    add_correlative_array_to_subject(nuevaCarrera, "Bases de Datos", correlatives_BasesDatos, 2);

    add_subject(nuevaCarrera, "Aprendizaje Automatico");
    char correlatives_AprendizajeAutomatico[] = {5};
    add_correlative_array_to_subject(nuevaCarrera, "Aprendizaje Automatico", correlatives_AprendizajeAutomatico, 1);

    add_subject(nuevaCarrera, "Procesamiento de Datos");
    char correlatives_ProcesamientoDatos[] = {4, 5};
    add_correlative_array_to_subject(nuevaCarrera, "Procesamiento de Datos", correlatives_ProcesamientoDatos, 2);

    add_subject(nuevaCarrera, "Mineria de Datos");
    char correlatives_MineriaDatos[] = {5};
    add_correlative_array_to_subject(nuevaCarrera, "Mineria de Datos", correlatives_MineriaDatos, 1);

    add_subject(nuevaCarrera, "Visualizacion de Datos");
    char correlatives_VisualizacionDatos[] = {5};
    add_correlative_array_to_subject(nuevaCarrera, "Visualizacion de Datos", correlatives_VisualizacionDatos, 1);

    add_subject(nuevaCarrera, "Proyecto de Ciencia de Datos");
    char correlatives_ProyectoCienciaDatos[] = {6, 7, 8, 9};
    add_correlative_array_to_subject(nuevaCarrera, "Proyecto de Ciencia de Datos", correlatives_ProyectoCienciaDatos, 4);

    add_subject(nuevaCarrera, "Etica en Ciencia de Datos");
    printf("Ciencia de datos completada!\n");
    return nuevaCarrera;
}

Career* initialize_computer_engineering(){
    Career *ingEnComp = create_career("Ingenieria en computacion");

    add_subject(ingEnComp, "AlgebraI");

    add_subject(ingEnComp, "AlgebraII");
    char correlatives_AlgebraII[] = {1};
    add_correlative_array_to_subject(ingEnComp, "AlgebraII", correlatives_AlgebraII, 1);

    add_subject(ingEnComp, "AnalisisMatematicoI");

    add_subject(ingEnComp, "AlgoritmosYProgramacionI");

    add_subject(ingEnComp, "SistemasDeRepresentacion");
    //printf("\n%d\n", ht_length(ingEnComp->subjectToID));
    add_subject(ingEnComp, "AlgoritmosYProgramacionII");
    char correlatives_AlgoritmosYProgramacionII[] = {4};
    add_correlative_array_to_subject(ingEnComp, "AlgoritmosYProgramacionII", correlatives_AlgoritmosYProgramacionII, 1);

    add_subject(ingEnComp, "AlgoritmosYProgramacionIII");
    char correlatives_AlgoritmosYProgramacionIII[] = {14};
    add_correlative_array_to_subject(ingEnComp, "AlgoritmosYProgramacionIII", correlatives_AlgoritmosYProgramacionIII, 1);


    add_subject(ingEnComp, "AnalisisMatematicoII");
    char correlatives_AnalisisMatematicoII[] = {3, 2};
    add_correlative_array_to_subject(ingEnComp, "AnalisisMatematicoII", correlatives_AnalisisMatematicoII, 2);

    add_subject(ingEnComp, "FisicaI"); // 8
    char correlatives_FisicaI[] = {3};
    add_correlative_array_to_subject(ingEnComp, "FisicaI", correlatives_FisicaI, 1);

    add_subject(ingEnComp, "FisicaII");
    char correlatives_FisicaII[] = {9, 8};
    add_correlative_array_to_subject(ingEnComp, "FisicaII", correlatives_FisicaII, 2);

    add_subject(ingEnComp, "FisicaIII");
    char correlatives_FisicaIII[] = {10};
    add_correlative_array_to_subject(ingEnComp, "FisicaIII", correlatives_FisicaIII, 1);

    add_subject(ingEnComp, "MatematicaDiscreta");
    char correlatives_MatematicaDiscreta[] = {2};
    add_correlative_array_to_subject(ingEnComp, "MatematicaDiscreta", correlatives_MatematicaDiscreta, 1);

    add_subject(ingEnComp, "DisenoLogico");
    char correlatives_DisenoLogico[] = {1, 5};
    add_correlative_array_to_subject(ingEnComp, "DisenoLogico", correlatives_DisenoLogico, 2);

    add_subject(ingEnComp, "EstructuraDeDatos");
    char correlatives_EstructuraDeDatos[] = {6};
    add_correlative_array_to_subject(ingEnComp, "EstructuraDeDatos", correlatives_EstructuraDeDatos, 1);

    add_subject(ingEnComp, "MatematicasEspeciales");
    char correlatives_MatematicasEspeciales[] = {8};
    add_correlative_array_to_subject(ingEnComp, "MatematicasEspeciales", correlatives_MatematicasEspeciales, 1);

    add_subject(ingEnComp, "ArquitecturaDeComputadorasI");
    char correlatives_ArquitecturaDeComputadorasI[] = {13};
    add_correlative_array_to_subject(ingEnComp, "ArquitecturaDeComputadorasI", correlatives_ArquitecturaDeComputadorasI, 1);

    add_subject(ingEnComp, "ArquitecturaDeComputadorasII");
    char correlatives_ArquitecturaDeComputadorasII[] = {10, 16};
    add_correlative_array_to_subject(ingEnComp, "ArquitecturaDeComputadorasII", correlatives_ArquitecturaDeComputadorasII, 2);

    add_subject(ingEnComp, "ProbabilidadYEstadistica");
    char correlatives_ProbabilidadYEstadistica[] = {8};
    add_correlative_array_to_subject(ingEnComp, "ProbabilidadYEstadistica", correlatives_ProbabilidadYEstadistica, 1);

    add_subject(ingEnComp, "FundamentosDeComputacion");
    char correlatives_FundamentosDeComputacion[] = {14, 12};
    add_correlative_array_to_subject(ingEnComp, "FundamentosDeComputacion", correlatives_FundamentosDeComputacion, 2);

    add_subject(ingEnComp, "SistemasOperativos");
    char correlatives_SistemasOperativos[] = {16};
    add_correlative_array_to_subject(ingEnComp, "SistemasOperativos", correlatives_SistemasOperativos, 1);

    add_subject(ingEnComp, "ComunicacionDeDatos");
    char correlatives_ComunicacionDeDatos[] = {18, 10, 20};
    add_correlative_array_to_subject(ingEnComp, "ComunicacionDeDatos", correlatives_ComunicacionDeDatos, 3);

    add_subject(ingEnComp, "TeoriaDeCircuitosElectronicos");
    char correlatives_TeoriaDeCircuitosElectronicos[] = {15, 10};
    add_correlative_array_to_subject(ingEnComp, "TeoriaDeCircuitosElectronicos", correlatives_TeoriaDeCircuitosElectronicos, 2);

    add_subject(ingEnComp, "LaboratorioDeMicroprocesadores");
    char correlatives_LaboratorioDeMicroprocesadores[] = {16, 14};
    add_correlative_array_to_subject(ingEnComp, "LaboratorioDeMicroprocesadores", correlatives_LaboratorioDeMicroprocesadores, 2);

    add_subject(ingEnComp, "RedesDeComputadoras");
    char correlatives_RedesDeComputadoras[] = {21};
    add_correlative_array_to_subject(ingEnComp, "RedesDeComputadoras", correlatives_RedesDeComputadoras, 1);

    add_subject(ingEnComp, "BasesDeDatos");
    char correlatives_BasesDeDatos[] = {18, 14};
    add_correlative_array_to_subject(ingEnComp, "BasesDeDatos", correlatives_BasesDeDatos, 2);

    add_subject(ingEnComp, "Electronica");
    char correlatives_Electronica[] = {11, 22};
    add_correlative_array_to_subject(ingEnComp, "Electronica", correlatives_Electronica, 2);

    add_subject(ingEnComp, "DisenoYArquitecturaDeSistemasDeComputacion");
    char correlatives_DisenoYArquitecturaDeSistemasDeComputacion[] = {17, 19, 20, 23};
    add_correlative_array_to_subject(ingEnComp, "DisenoYArquitecturaDeSistemasDeComputacion", correlatives_DisenoYArquitecturaDeSistemasDeComputacion, 4);

    add_subject(ingEnComp, "AnalisisNumerico");
    char correlatives_AnalisisNumerico[] = {15};
    add_correlative_array_to_subject(ingEnComp, "AnalisisNumerico", correlatives_AnalisisNumerico, 1);

    add_subject(ingEnComp, "Quimica");
    char correlatives_Quimica[] = {9};
    add_correlative_array_to_subject(ingEnComp, "Quimica", correlatives_Quimica, 1);

    add_subject(ingEnComp, "ProcesamientoDeSenales");
    char correlatives_ProcesamientoDeSenales[] = {15, 18, 23};
    add_correlative_array_to_subject(ingEnComp, "ProcesamientoDeSenales", correlatives_ProcesamientoDeSenales, 3);

    add_subject(ingEnComp, "IngenieriaDeCalidad");
    char correlatives_IngenieriaDeCalidad[] = {27};
    add_correlative_array_to_subject(ingEnComp, "IngenieriaDeCalidad", correlatives_IngenieriaDeCalidad, 1);

    add_subject(ingEnComp, "ConstruccionDeSistemasDeComputacion");
    char correlatives_ConstruccionDeSistemasDeComputacion[] = {27};
    add_correlative_array_to_subject(ingEnComp, "ConstruccionDeSistemasDeComputacion", correlatives_ConstruccionDeSistemasDeComputacion, 1);

    add_subject(ingEnComp, "SistemasEmbebidos");
    char correlatives_SistemasEmbebidos[] = {27, 26};
    add_correlative_array_to_subject(ingEnComp, "SistemasEmbebidos", correlatives_SistemasEmbebidos, 2);

    add_subject(ingEnComp, "SistemasDeTiempoReal");
    char correlatives_SistemasDeTiempoReal[] = {27, 26};
    add_correlative_array_to_subject(ingEnComp, "SistemasDeTiempoReal", correlatives_SistemasDeTiempoReal, 2);

    add_subject(ingEnComp, "IngenieriaDeRequerimientos");
    char correlatives_IngenieriaDeRequerimientos[] = {31};
    add_correlative_array_to_subject(ingEnComp, "IngenieriaDeRequerimientos", correlatives_IngenieriaDeRequerimientos, 1);

    add_subject(ingEnComp, "IngenieriaDeSoftware");
    char correlatives_IngenieriaDeSoftware[] = {31};
    add_correlative_array_to_subject(ingEnComp, "IngenieriaDeSoftware", correlatives_IngenieriaDeSoftware, 1);

    add_subject(ingEnComp, "OrganizacionDeProyectos");

    add_subject(ingEnComp, "MetodologiaDeLaInvestigacion");

    add_subject(ingEnComp, "SeguridadSaludOcupacionalYMedioAmbiente");
    char correlatives_SeguridadSaludOcupacionalYMedioAmbiente[] = {29};
    add_correlative_array_to_subject(ingEnComp, "SeguridadSaludOcupacionalYMedioAmbiente", correlatives_SeguridadSaludOcupacionalYMedioAmbiente, 1);

    add_subject(ingEnComp, "EconomiaYLegislacion");

    add_subject(ingEnComp, "PracticaProfesionalSupervisada");

    add_subject(ingEnComp, "TrabajoFinalIntegrador");
    char correlatives_TrabajoFinalIntegrador[] = {37};
    add_correlative_array_to_subject(ingEnComp, "TrabajoFinalIntegrador", correlatives_TrabajoFinalIntegrador, 1);

    add_subject(ingEnComp, "InglesBasico");

    add_subject(ingEnComp, "InglesTecnico");
    char correlatives_InglesTecnico[] = {43};
    add_correlative_array_to_subject(ingEnComp, "InglesTecnico", correlatives_InglesTecnico, 1);

    add_subject(ingEnComp, "IntroduccionALaProblematicaDelMundoContemporaneo");

    add_subject(ingEnComp, "ProblemasDeHistoriaDelSigloXX");

    add_subject(ingEnComp, "CuestionesDeSociologiaEconomiaYPolitica");
    printf("si llegue");
    add_subject(ingEnComp, "CulturaContemporanea");
    printf("Ingeniera en computacion completada!\n");
    return ingEnComp;
}
Career* initialize_lollxd() {

    Career *lolCarrera = create_career("League Of Legends");

    add_subject(lolCarrera, "HistoriadeRunaterra");

    add_subject(lolCarrera, "EstrategiasdeJuego");
    char correlatives_EstrategiasJuego[] = {1};
    add_correlative_array_to_subject(lolCarrera, "EstrategiasdeJuego", correlatives_EstrategiasJuego, 1);

    add_subject(lolCarrera, "MecanicasdeCampeonesI");
    char correlatives_MecanicasCampeonesI[] = {1};
    add_correlative_array_to_subject(lolCarrera, "MecanicasdeCampeonesI", correlatives_MecanicasCampeonesI, 1);

    add_subject(lolCarrera, "Mecanicas de Campeones II");
    char correlatives_MecanicasCampeonesII[] = {3};
    add_correlative_array_to_subject(lolCarrera, "Mecanicas de Campeones II", correlatives_MecanicasCampeonesII, 1);

    add_subject(lolCarrera, "Analisis de Partidas");
    char correlatives_AnalisisPartidas[] = {2, 3};
    add_correlative_array_to_subject(lolCarrera, "Analisis de Partidas", correlatives_AnalisisPartidas, 2);

    add_subject(lolCarrera, "Permaban Darius");
    char correlatives_DisenoMapas[] = {1};
    add_correlative_array_to_subject(lolCarrera, "Permaban Darius", correlatives_DisenoMapas, 1);

    add_subject(lolCarrera, "Balance de Campeones");
    char correlatives_BalanceCampeones[] = {3, 4};
    add_correlative_array_to_subject(lolCarrera, "Balance de Campeones", correlatives_BalanceCampeones, 2);

    add_subject(lolCarrera, "Comunicacion en Equipo");

    add_subject(lolCarrera, "Psicologia del Jugador");
    char correlatives_PsicologiaJugador[] = {5};
    add_correlative_array_to_subject(lolCarrera, "Psicologia del Jugador", correlatives_PsicologiaJugador, 1);

    add_subject(lolCarrera, "Marketing de eSports");

    add_subject(lolCarrera, "Gestion de Tilt");
    char correlatives_GestionEquipos[] = {5, 6};
    add_correlative_array_to_subject(lolCarrera, "Gestion de Tilt", correlatives_GestionEquipos, 2);

    add_subject(lolCarrera, "Streaming y Contenido");
    char correlatives_StreamingContenido[] = {7};
    add_correlative_array_to_subject(lolCarrera, "Streaming y Contenido", correlatives_StreamingContenido, 1);

    add_subject(lolCarrera, "Casting y Narracion de Partidas");
    char correlatives_CastingNarracion[] = {10};
    add_correlative_array_to_subject(lolCarrera, "Casting y Narracion de Partidas", correlatives_CastingNarracion, 1);

    add_subject(lolCarrera, "Inteligencia Artificial en eSports");
    char correlatives_IAEsports[] = {9};
    add_correlative_array_to_subject(lolCarrera, "Inteligencia Artificial en eSports", correlatives_IAEsports, 1);

    add_subject(lolCarrera, "Desarrollo de Herramientas para Jugadores");
    char correlatives_DesarrolloHerramientas[] = {9};
    add_correlative_array_to_subject(lolCarrera, "Desarrollo de Herramientas para Jugadores", correlatives_DesarrolloHerramientas, 1);

    add_subject(lolCarrera, "Gestion de Torneos y Eventos eSports");
    char correlatives_GestionTorneosEventos[] = {8, 10};
    add_correlative_array_to_subject(lolCarrera, "Gestion de Torneos y Eventos eSports", correlatives_GestionTorneosEventos, 2);

    add_subject(lolCarrera, "Diseno de Interfaz de Usuario para Juegos");
    char correlatives_DiseñoInterfaz[] = {11};
    add_correlative_array_to_subject(lolCarrera, "Diseno de Interfaz de Usuario para Juegos", correlatives_DiseñoInterfaz, 1);

    add_subject(lolCarrera, "Optimizacion de Rendimiento en Juegos");
    char correlatives_OptimizacionRendimiento[] = {11, 12};
    add_correlative_array_to_subject(lolCarrera, "Optimizacion de Rendimiento en Juegos", correlatives_OptimizacionRendimiento, 2);

    printf("Lolcito instalado\n");
    return lolCarrera;
}
LinkedList * create_sts(){
    LinkedList * st = create_list();
   //list_add_node(st, st_create_student("Alice Smith", student1_dt, 1001));

    Date* student2_dt = construct_date(8, 5, 2001);
    list_add_node(st, st_create_student("Bobobo Johnson", student2_dt, 1002));

    Date* student3_dt = construct_date(15, 9, 2000);
    list_add_node(st, st_create_student("Emma Davis", student3_dt, 1003));

    Date* student4_dt = construct_date(21, 7, 2001);
    list_add_node(st, st_create_student("David Wilson", student4_dt, 1004));

    Date* student5_dt = construct_date(9, 4, 2000);
    list_add_node(st, st_create_student("Olivia Martinez", student5_dt, 1005));

    Date* student6_dt = construct_date(5, 11, 2001);
    list_add_node(st, st_create_student("James Rodriguez", student6_dt, 1006));

    Date* student7_dt = construct_date(17, 2, 2000);
    list_add_node(st, st_create_student("Sophia Thompson", student7_dt, 1007));

    Date* student8_dt = construct_date(24, 10, 2001);
    list_add_node(st, st_create_student("Benjamin Adams", student8_dt, 1008));

    Date* student9_dt = construct_date(13, 6, 2000);
    list_add_node(st, st_create_student("Isabella Brown", student9_dt, 1009));

    Date* student10_dt = construct_date(29, 3, 2001);
    list_add_node(st, st_create_student("Lucas Taylor", student10_dt, 1010));

    Date* student11_dt = construct_date(7, 11, 2000);
    list_add_node(st, st_create_student("Mia Garcia", student11_dt, 1011));

    Date* student12_dt = construct_date(19, 5, 2001);
    list_add_node(st, st_create_student("Jacob Clark", student12_dt, 1012));

    Date* student13_dt = construct_date(4, 9, 2000);
    list_add_node(st, st_create_student("Ava Wright", student13_dt, 1013));

    Date* student14_dt = construct_date(12, 8, 2001);
    list_add_node(st, st_create_student("Liam Scott", student14_dt, 1014));

    Date* student15_dt = construct_date(27, 1, 2000);
    list_add_node(st, st_create_student("Emily Rodriguez", student15_dt, 1015));

    Date* student16_dt = construct_date(16, 11, 2001);
    list_add_node(st, st_create_student("Noah Baker", student16_dt, 1016));

    Date* student17_dt = construct_date(1, 7, 2000);
    list_add_node(st, st_create_student("Charlotte Phillips", student17_dt, 1017));

    Date* student18_dt = construct_date(10, 9, 2001);
    list_add_node(st, st_create_student("Alexander Reed", student18_dt, 1018));

    Date* student19_dt = construct_date(26, 4, 2000);
    list_add_node(st, st_create_student("Grace Walker", student19_dt, 1019));

    Date* student20_dt = construct_date(14, 10, 2001);
    list_add_node(st, st_create_student("Ethan Cooper", student20_dt, 1020));

    Date* student21_dt = construct_date(22, 3, 2000);
    list_add_node(st, st_create_student("Samantha Turner", student21_dt, 1021));

    Date* student22_dt = construct_date(9, 8, 2001);
    list_add_node(st, st_create_student("Henry Harris", student22_dt, 1022));

    Date* student23_dt = construct_date(18, 11, 2000);
    list_add_node(st, st_create_student("Lily Foster", student23_dt, 1023));

    Date* student24_dt = construct_date(7, 5, 2001);
    list_add_node(st, st_create_student("William Reed", student24_dt, 1024));

    Date* student25_dt = construct_date(12, 2, 2000);
    list_add_node(st, st_create_student("Victoria Hayes", student25_dt, 1025));

    Date* student26_dt = construct_date(29, 10, 2001);
    list_add_node(st, st_create_student("Gabriel Murphy", student26_dt, 1026));

    Date* student27_dt = construct_date(6, 6, 2000);
    list_add_node(st, st_create_student("Zoe Parker", student27_dt, 1027));

    Date* student28_dt = construct_date(15, 1, 2001);
    list_add_node(st, st_create_student("Christopher Wood", student28_dt, 1028));

    Date* student29_dt = construct_date(23, 9, 2000);
    list_add_node(st, st_create_student("Madison Green", student29_dt, 1029));

    Date* student30_dt = construct_date(4, 12, 2001);
    list_add_node(st, st_create_student("Daniel Hill", student30_dt, 1030));
    return st;
}


