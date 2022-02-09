<?php
/**
 * La configuration de base de votre installation WordPress.
 *
 * Ce fichier est utilisé par le script de création de wp-config.php pendant
 * le processus d’installation. Vous n’avez pas à utiliser le site web, vous
 * pouvez simplement renommer ce fichier en « wp-config.php » et remplir les
 * valeurs.
 *
 * Ce fichier contient les réglages de configuration suivants :
 *
 * Réglages MySQL
 * Préfixe de table
 * Clés secrètes
 * Langue utilisée
 * ABSPATH
 *
 * @link https://fr.wordpress.org/support/article/editing-wp-config-php/.
 *
 * @package WordPress
 */

// ** Réglages MySQL - Votre hébergeur doit vous fournir ces informations. ** //
/** Nom de la base de données de WordPress. */
define( 'DB_NAME', 'wordpress' );

/** Utilisateur de la base de données MySQL. */
define( 'DB_USER', 'user' );

/** Mot de passe de la base de données MySQL. */
define( 'DB_PASSWORD', 'password' );

/** Adresse de l’hébergement MySQL. */
define( 'DB_HOST', 'localhost' );

/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/**
 * Type de collation de la base de données.
 * N’y touchez que si vous savez ce que vous faites.
 */
define( 'DB_COLLATE', '' );

/**#@+
 * Clés uniques d’authentification et salage.
 *
 * Remplacez les valeurs par défaut par des phrases uniques !
 * Vous pouvez générer des phrases aléatoires en utilisant
 * {@link https://api.wordpress.org/secret-key/1.1/salt/ le service de clés secrètes de WordPress.org}.
 * Vous pouvez modifier ces phrases à n’importe quel moment, afin d’invalider tous les cookies existants.
 * Cela forcera également tous les utilisateurs à se reconnecter.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '`)SX]>+5&:LQ>&UHlvv4q[a,}h41F_!?h6A^Z$RBoY2Ae|>bzhu%WH&DL:NHr Nm' );
define( 'SECURE_AUTH_KEY',  'MQFvz+u?1v]pgWQ{*$4l^Yp[bt*y}BSsetRqIHn=vgN9L,6CX4.ZH04pWMPo*mHk' );
define( 'LOGGED_IN_KEY',    '(!{t&fq8:p0w_MNn+II?;QJ7:k+PJ Z0+lxSI{G8iG`14Rrk>]vl~C2PKY-BeZhr' );
define( 'NONCE_KEY',        'c@g@-Qd(xhl1L;o!R:$0FY#(p!!2sF(3`hdUJ}n[YnUNkBFc6o3!gTb1XNtL*![h' );
define( 'AUTH_SALT',        '_DRE7KFzlsn!p?g q[?f:[y]+:m=~]Kvhk:I&`tRRe}T1`9 1LtOaYkvpX[QpAGC' );
define( 'SECURE_AUTH_SALT', 'nd#H__w?W5cNPZ<~rkr5.*VKN:t:$k$pj+%`i0:n;uE6NNXoV07-SvLi4#qLyGf4' );
define( 'LOGGED_IN_SALT',   'nsy[@GjG/jhIuT3(sv P:HYlgso%`WXES@%YC<6GaShGGH-c&<GuPO)DHr;GvG|V' );
define( 'NONCE_SALT',       'T}e:t30<. ]#M%hpFJ!s[#t!>DL$,p+ZfS:F^*Dp&9v]$%Z+hAe/gv;QFrugu6^&' );
/**#@-*/

/**
 * Préfixe de base de données pour les tables de WordPress.
 *
 * Vous pouvez installer plusieurs WordPress sur une seule base de données
 * si vous leur donnez chacune un préfixe unique.
 * N’utilisez que des chiffres, des lettres non-accentuées, et des caractères soulignés !
 */
$table_prefix = 'wp_';

/**
 * Pour les développeurs : le mode déboguage de WordPress.
 *
 * En passant la valeur suivante à "true", vous activez l’affichage des
 * notifications d’erreurs pendant vos essais.
 * Il est fortemment recommandé que les développeurs d’extensions et
 * de thèmes se servent de WP_DEBUG dans leur environnement de
 * développement.
 *
 * Pour plus d’information sur les autres constantes qui peuvent être utilisées
 * pour le déboguage, rendez-vous sur le Codex.
 *
 * @link https://fr.wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* C’est tout, ne touchez pas à ce qui suit ! Bonne publication. */

/** Chemin absolu vers le dossier de WordPress. */
if ( ! defined( 'ABSPATH' ) )
  define( 'ABSPATH', dirname( __FILE__ ) . '/' );

/** Réglage des variables de WordPress et de ses fichiers inclus. */
require_once( ABSPATH . 'wp-settings.php' );

