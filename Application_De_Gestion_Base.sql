-- Base créé le 4/9/2019 par Sylvain Bourbousse --

-- Suppression des tables existantes --
drop table if exists User;
drop table if exists Produit;
drop table if exists Rayon;
drop table if exists Unite;

-- Création des tables --
create table Produit(
	produitId int auto_increment primary key,
	produitLibelle varchar(100),
	produitDescription varchar(512),
	produitPrixUnitaire float,
	uniteId tinyint,
	produitImage varchar(256),
	rayonId mediumInt
)engine=innodb charset=utf8;

create table Rayon(
	rayonId mediumint auto_increment primary key,
	rayonLibelle varchar(100),
	rayonImage varchar(256)
)engine=innodb charset=utf8;

create table Unite(
	uniteId tinyint primary key,
	uniteLibelle varchar(32),
	uniteLettre varchar(3)
)engine=innodb charset=utf8;

create table User(
	userUsername varchar(64),
	userPassword varchar(64)
)engine=innodb charset=utf8;


alter table Produit add foreign key (rayonId) references Rayon(rayonId);
alter table Produit add foreign key (uniteId) references Unite(uniteId);
