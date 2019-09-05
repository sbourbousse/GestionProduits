-- Créé le 4/9/2019 par Sylvain Bourbousse --

-- Suppression des données existantes --
delete from Produit ;
delete from Rayon ;

-- Ajout des valeurs --
insert into Rayon (rayonId,rayonLibelle) values (232,'Charcuterie'),
	(111,'Vin et alcools'),
	(133,'Confisserie et chocolat'),
	(666,'Bio'),
	(401,'Poissonnerie');

insert into Produit (produitId,produitLibelle,produitDescription,produitPrixUnitaire,produitUnite,produitImage,rayonId) values (4012,'M&Ms Sachet 450g','',4.45,'g','/home/sbourbousse/Images/4012.png',133),
	(5628,'Jack Daniel Honey 70cl',"La vente d'alcool est interdit au personne de moins de 18 ans",20.32,'L','/home/sbourbousse/Images/5628.png',111);


insert into User (userUsername, userPassword) values ('sylvain','mdps');
