-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le :  mer. 23 oct. 2019 à 13:11
-- Version du serveur :  10.4.6-MariaDB
-- Version de PHP :  7.3.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `Musique`
--

-- --------------------------------------------------------

--
-- Structure de la table `albums`
--

CREATE TABLE `albums` (
  `id` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `artiste` int(11) NOT NULL,
  `pistes` int(11) NOT NULL,
  `sortie` year(4) NOT NULL,
  `couverture` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `albums`
--

INSERT INTO `albums` (`id`, `nom`, `artiste`, `pistes`, `sortie`, `couverture`) VALUES
(1, 'Hypnotize', 1, 12, 2005, 'https://upload.wikimedia.org/wikipedia/en/9/9a/System_Of_A_Down-Hypnotize.jpg');

-- --------------------------------------------------------

--
-- Structure de la table `groupes`
--

CREATE TABLE `groupes` (
  `ID` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `chanteur` varchar(255) NOT NULL,
  `origine` varchar(255) NOT NULL,
  `genre` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `groupes`
--

INSERT INTO `groupes` (`ID`, `nom`, `chanteur`, `origine`, `genre`) VALUES
(1, 'System Of A Down', 'Serj Tankian', 'Glendale', 'nu metal, hard rock, heavy metal, alternative metal'),
(2, 'Mika', 'Michael Holbrook', 'Beyrouth', 'pop, pop-rock, classique'),
(3, 'Muse', 'Matthew Bellamy', 'Royaume-Uni', 'rock alternatif, rock progressif, new prog, art rock'),
(4, 'aiden', 'William Francis', 'Seattle', 'Horror punk, post-hardcore, gothic rock, screamo'),
(5, 'The Beatles', 'John Lennon', 'Liverpool', 'Rock, pop, psychedelique'),
(6, 'Booba', 'Elie Yaffa', 'Boulogne-Billancourt', 'hip-hop, rap francais, trap, gansta rap');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `albums`
--
ALTER TABLE `albums`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `groupes`
--
ALTER TABLE `groupes`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `albums`
--
ALTER TABLE `albums`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `groupes`
--
ALTER TABLE `groupes`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
