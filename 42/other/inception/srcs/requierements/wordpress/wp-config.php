<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to wp-config.php
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'aedouard' );

/** Database password */
define( 'DB_PASSWORD', 'nelito444^^' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

define('AUTH_KEY',         '&10%B*Vn)q-9D6<t38)+E*w@GRxYwY,St]+UZ}*9+n9vt||oPtZ6(dY~l=uv.>LP');
define('SECURE_AUTH_KEY',  'jv(wuQBX( &0M/u[{S{[Xf+3:PsH%(Sn>mq51:wxo(L![SmcEV8Rd%Hk/i~`zy7 ');
define('LOGGED_IN_KEY',    ';]eJ)4HXMw;Uy.*1D!8=|dmM66V~UuvjzJE-(~#RAs67)Qp4cJ={D;Hq-mc,)K;V');
define('NONCE_KEY',        'dP1H nAl%7, TRgSdW1x6n0+cdCYPwp|9Nhqz#xJM*evFf;g2/rBz)Jg1E<nGaJJ');
define('AUTH_SALT',        '~:]Pn%ibjuXI2q9fOHFHYi4$+m&,720.f?{+NaHvPQ*+d5Qca]I.b&JZL:L8K/g6');
define('SECURE_AUTH_SALT', '|V5)IUoRipx4:+Bn6m?}<s?[oi4u2dYj<80-*+Z-r2Jm?X<$+MytG4#iVnN#OR=>');
define('LOGGED_IN_SALT',   'a[Z<ibM1FbQ9Bu1Zx4UUk:@+_-_7CoTgjQ^k/!$:|)|/L|<f,U4pVv^9IVnha_E+');
define('NONCE_SALT',       '6o8^1-!?CNn3.`$,sk(CX}wn8OYY,J-WJm!-#iBssHn+M?0`ny)=Zm^D4<xM~U+a');
/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
 $table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the stop editing line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}
/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';

