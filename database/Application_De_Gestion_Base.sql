-- Base créé le 4/9/2019 par Sylvain Bourbousse --

-- Suppression des tables existantes --
drop table if exists Produit;
drop table if exists Rayon;
drop table if exists Unite;
drop table if exists User;

-- Création des tables --
create table Unite(
	uniteId tinyint primary key,
	uniteLibelle varchar(64)
)engine=innodb charset=utf8;

create table Produit(
	produitId int primary key auto_increment,
	produitLibelle varchar(100),
	produitDescription varchar(512),
	produitPrixUnitaire float,
	uniteId tinyint references Unite(uniteId),
	produitImage varchar(128),
	rayonId mediumInt references Rayon(rayonId)
)engine=innodb charset=utf8;

create table Rayon(
	rayonId mediumint primary key auto_increment,
	rayonLibelle varchar(100),
	rayonImage varchar(256)
)engine=innodb charset=utf8;

create table User(
	userUsername varchar(64),
	userPassword varchar(64)
)engine=innodb charset=utf8;
