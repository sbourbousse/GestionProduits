-- Base créé le 4/9/2019 par Sylvain Bourbousse --

-- Suppression des tables existantes --
drop table if exists Produit;
drop table if exists Rayon;

-- Création des tables --
create table Produit(
	produitId int primary key,
	produitLibelle varchar(100),
	produitDescription varchar(512),
	produitPrixUnitaire float,
	produitUnite varchar(5),
	produitImage varchar(128),
	rayonId mediumInt
)engine=innodb charset=utf8;

create table Rayon(
	rayonId mediumint primary key,
	rayonLibelle varchar(100)
)engine=innodb charset=utf8;

create table User(
	userUsername varchar(64),
	userPassword varchar(64)
)engine=innodb charset=utf8;


alter table Produit add foreign key Produit(rayonId) references Rayon(rayonId);
